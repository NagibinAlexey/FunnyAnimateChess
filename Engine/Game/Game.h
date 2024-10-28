#pragma once

#include "../Utility.h"
#include <vector>
#include <string>
#include <fstream>

namespace FAC {

	class Game {
	public:
		Game(std::string pgn_filename) {
			parsePGN(pgn_filename);
		}

	private:
		void parsePGN(std::string pgn_filename);
		void parseMoves(std::string& moves);

	private:
		std::vector <std::pair<std::string, std::string>> moves_;
		Player white_;
		Player black_;
	};

} //namespace FAC