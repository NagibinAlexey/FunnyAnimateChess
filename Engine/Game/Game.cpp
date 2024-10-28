#include "Game.h"
#include <sstream>
#include <iostream>

namespace FAC {

    void Game::parseMoves(std::string& moves) {
        std::istringstream iss(moves);
        std::string move;

        int moveNumber = 0;

        while (iss >> move) {
            if (move == "0-1" || move == "1-0" || move == "1/2-1/2") break;
            if (move.back() == '.') {
                moveNumber++;
            }
            else {
                if (moveNumber > 0) {
                    if (moves_.size() < moveNumber) {
                        moves_.emplace_back(move, "");
                    }
                    else {
                        moves_[moveNumber - 1].first = move;
                    }
                }
                if (iss >> move) {
                    if (moveNumber > 0) {
                        moves_[moveNumber - 1].second = move;
                    }
                }
            }
        }
    }

	void Game::parsePGN(std::string pgn_filename) {
        // open file for reading
        std::ifstream istrm(pgn_filename, std::ios::binary);
        if (!istrm.is_open())
            std::cout << "failed to open " << pgn_filename << '\n';
        else
        {
            // read lines from file
            std::string line;
            while (std::getline(istrm, line)) {
                if (!line.empty()) {
                    if (line.substr(1, 6) == "White ") {
                        white_.name = line.substr(8, line.size() - 10);
                    }
                    else if (line.substr(1, 6) == "Black ") {
                        black_.name = line.substr(8, line.size() - 10);
                    }
                    else if (line.substr(1, 8) == "WhiteElo") {
                        white_.Elo = std::stoi(line.substr(11, line.size() - 13));
                    }
                    else if (line.substr(1, 8) == "BlackElo") {
                        black_.Elo = std::stoi(line.substr(11, line.size() - 13));
                    }
                    else if (line.substr(0, 2) == "1.") {
                        parseMoves(line);
                    }
                }
            }
        }
        istrm.close();
	}

} //namespace FAC