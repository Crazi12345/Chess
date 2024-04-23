cmake_minimum_required(VERSION 3.18.4)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Chess
        src/Bishop.cpp
        src/header/Pieces/Bishop.h
        src/Board.cpp
        src/header/Board.h
        src/Game.cpp
        src/header/Game.h
        src/King.cpp
        src/header/Pieces/King.h
        src/Knight.cpp
        src/header/Pieces/Knight.h
        src/main.cpp
        src/Pawn.cpp
        src/header/Pieces/Pawn.h
        src/Piece.cpp
        src/header/Piece.h
        src/Queen.cpp
        src/header/Pieces/Queen.h
        src/Rook.cpp
        src/header/Pieces/Rook.h src/Parser.cpp src/header/Parser.h src/Player.cpp src/header/Player.h)






