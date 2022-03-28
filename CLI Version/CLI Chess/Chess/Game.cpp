//
// Created by Patrick Larsen on 15-11-2021.
//

#include "Game.h"
#include "Player.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
using namespace std;


Game::Game() {

    Parser p(&board);
    parser = p;
  }

void Game::Setup() {
  //  board.PrettyPrint();
     Player whitePlayer = Player('w',&board);
     Player blackPlayer = Player('b',&board);
     currentPlayer = whitePlayer;
     alternatePlayer = blackPlayer;
   //cout<<"pieces list: "<<c¨urrentPlayer.getPieces().size()<<endl;
   // PlacePieces();
     currentPlayer.PlacePieces();
     alternatePlayer.PlacePieces();
        //board.PrettyPrint();
    Play();
}

void Game::Play() {
    if(currentPlayer.getName()=='w'){
    cout << "White's turn"<<endl;
    }
    else {
        cout << "Black's turn"<<endl;
    }
    board.resetBoard();
     currentPlayer.PlacePieces();
     alternatePlayer.PlacePieces();
    board.PrettyPrint();

    parser.Command(&currentPlayer,&alternatePlayer);
    cout << "\nPlease press any key to continue...";

    cin.get();
    SwitchPlayer();
    system("clear");
    Play();

}




Player Game::getCurrentPlayer(){
    return currentPlayer;
}
void Game::SwitchPlayer(){
    Player temp;
    temp = currentPlayer;
    currentPlayer = alternatePlayer;
    alternatePlayer = temp;
}
