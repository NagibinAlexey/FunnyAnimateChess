#pragma once

#include "ChessSquare.h"
#include <vector>

namespace FAC {

	class ChessBoard {
		public:
			ChessBoard() {}

		private:
		std::vector<std::vector<FAC::ChessSquare>> board_;
	}

} //namespace FAC