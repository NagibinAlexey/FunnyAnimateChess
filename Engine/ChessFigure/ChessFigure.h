#pragma once

#include <memory>

namespace FAC {

	enum class FigureColor
	{
		BLACK,
		WHITE
	};

	class ChessFigure {
		public:
			virtual bool isAlive() const = 0;
	}

} //namespace FAC