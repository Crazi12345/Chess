cmake_minimum_required(VERSION 3.20)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess
    main.cpp
    Board.cpp Board.h
    Game.cpp Game.h
    Parser.cpp Parser.h
    Player.cpp Player.h
    Piece.h Piece.cpp
    Pawn.h Pawn.cpp
    King.h King.cpp
    Queen.h Queen.cpp
    Bishop.h Bishop.cpp
    Rook.h Rook.cpp
    Knight.h Knight.cpp

    )

