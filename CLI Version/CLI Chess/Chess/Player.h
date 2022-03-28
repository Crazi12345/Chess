//
// Created by patri on 16-12-2021.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H


#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include <iostream>
#include "Board.h"

class Player {
public:
    Player();
    Player(char name,Board* b);
    std::vector<Piece*> createPieces();
    char getName();
    void PlacePieces();
    std::vector<Piece*> getPieces();
private:
std::vector<Piece*> pieces;
    char name;
    Board* board;
};


#endif //CHESS_PLAYER_H
