#pragma once

#include "ChessFigure.h"
#include <vector>
#include <memory>

namespace FAC {

	enum class SquareColor
	{
		BLACK,
		WHITE
	};

	class ChessSquare {
		public:
			ChessSquare() {}

			std::shared_ptr<FAC::ChessFigure> getFigure();
			void setFigure();

			bool isEmpty();
			void setColor();
			SquareColor getColor();

		private:
			bool empty_ = true;
			SquareColor color_ = SquareColor::WHITE;
			std::shared_ptr<FAC::ChessFigure> figure_ptr_ = nullptr;
	}

} //namespace FAC