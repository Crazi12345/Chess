//
// Created by patri on 15-11-2021.
//

#pragma once
#include <vector>
#include "Board.h"
#include "Parser.h"
#include "Player.h"

class Game
{


public:

    Game();
    void Setup();
    Player getCurrentPlayer();
    void SwitchPlayer();

private:

    Player currentPlayer;
    Player alternatePlayer;
    Board board;
    Parser parser;




protected:
    void Play();





};

