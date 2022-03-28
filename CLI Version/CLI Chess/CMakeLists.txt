cmake_minimum_required(VERSION 3.18.4)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(Chess)

add_executable(Chess
        Chess/Bishop.cpp
        Chess/header/Pieces/Bishop.h
        Chess/Board.cpp
        Chess/header/Board.h
        Chess/Game.cpp
        Chess/header/Game.h
        Chess/King.cpp
        Chess/header/Pieces/King.h
        Chess/Knight.cpp
        Chess/header/Pieces/Knight.h
        Chess/main.cpp
        Chess/Pawn.cpp
        Chess/header/Pieces/Pawn.h
        Chess/Piece.cpp
        Chess/header/Piece.h
        Chess/Queen.cpp
        Chess/header/Pieces/Queen.h
        Chess/Rook.cpp
        Chess/header/Pieces/Rook.h Chess/Parser.cpp Chess/header/Parser.h Chess/Player.cpp Chess/header/Player.h)


       


        
