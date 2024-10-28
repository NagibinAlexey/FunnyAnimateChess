set(PROJECT_NAME Engine)

include_directories(ChessBoard)
include_directories(ChessFigure)
include_directories(ChessSquare)
include_directories(Game)

set(SOURCE_FILES
    main.cpp
	Utility.h
	ChessBoard/ChessBoard.h
	ChessFigure/ChessFigure.h
	ChessSquare/ChessSquare.h
	Game/Game.h
	Game/Game.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
