//
// Created by patri on 19-11-2021.
//

#ifndef CHESS_PARSER_H
#define CHESS_PARSER_H

#include <string>
#include <vector>
#include <map>
#include "Player.h"
#include "Board.h"

class Parser {
public:
    Parser();
    Parser(Board* b);
    void Command(Player* c, Player* a);
    void selectCommand();
    Piece* Find(int x,int y,Player* player);
    Piece* FindAlternate(int x, int y);
    void moveCommand();
    void helpCommand();
    int AsciiToInt(int ascii);
  //  void printPieceName(Piece piece);
    void printWord();
    void endCommand();

private:
    std::vector<std::string> words;
    int indexForCommand=0;
    std::string wordOne;
    std::string wordTwo;
    std::string wordThree;
    std::map<char,int> letter;
    Player* current;
    Player* alternate;
    Board* board;

};


#endif //CHESS_PARSER_H
