//
// Created by patri on 15-11-2021.
//

#include "Board.h"
#include <iostream>
using namespace std;


Board::Board() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            (j + i) % 2 == 0 ? emptyBoard[i][j] = typeOfBoardSquare[1] : emptyBoard[i][j] = typeOfBoardSquare[0];
            (j + i) % 2 == 0 ? board[i][j] = typeOfBoardSquare[1] : board[i][j] = typeOfBoardSquare[0];
        }
    }
}


void Board::PrettyPrint() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j]<<"  ";
        }
        cout << "  " << 1+i << '\n' << endl;
    }
    string letters = "abcdefgh";
    cout << "  ";
    for (int k = 0; k < 8; k++) {
        cout <<  letters[k]<< "     ";
    }
    cout << endl;

}

void Board::setField(int x, int y, string piece)
{
    board[x][y] = "["+piece+"]";
}

void Board::resetBoard(){

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          board[i][j]= emptyBoard[i][j];
        }
    }
}













