//
// Created by patri on 15-11-2021.
//

#pragma once
#include <string>
using namespace std;
class Board
{

public:
    Board();
    void PrettyPrint();
    void setField(int x, int y, string piece);
    void resetBoard();


private:
    string emptyBoard[8][8];
    string board[8][8];
    string typeOfBoardSquare[2] = { "[  ]","[--]" };


};

