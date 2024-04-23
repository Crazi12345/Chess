//
// Created by patri on 16-12-2021.
//

#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "Player.h"

using namespace std;

Player::Player(){}
Player::Player(char name, Board* b) {
    board = b;
this->name=name;
    pieces = this->createPieces();
    //cout<<"pieces list: "<<pieces.size()<<endl;



}


std::vector<Piece*> Player::createPieces() {
    int place;
    if(name == 'w'){
       place = 7;
    for (int i = 0; i < 8; i++) {
       pieces.push_back(new Pawn(6, i, 'P', name));
        }
    }
    else{
        place = 0;
        for (int i = 0; i < 8; i++) {

                pieces.push_back(new Pawn(1, i, 'P', name));
            }}

         /*
          * for future referrence
          *  King k= King(place,4,'P',name);
           Queen q(place, 3, 'Q', name);
           Bishop b(place, 2, 'B', name);
           Bishop bb(place, 5, 'B', name);
           Rook r(place, 0,'R', name);
           Rook rr(place, 7, 'R', name);
           Knight n(place, 1, 'N', name);
           Knight nn(place, 6, 'N', name);
*/
           pieces.push_back(new King(place,4,'K',name));
           pieces.push_back(new Queen(place, 3, 'Q', name));
           pieces.push_back(new Bishop(place, 2, 'B', name));
           pieces.push_back(new Bishop(place, 5, 'B', name));
           pieces.push_back(new Rook(place, 0,'R', name));
           pieces.push_back(new Rook(place, 7, 'R', name));
           pieces.push_back(new Knight (place, 1, 'N', name));
           pieces.push_back(new Knight (place, 6, 'N', name));
           return pieces;

}

std::vector<Piece*> Player::getPieces()
{
    return pieces;
}

char Player::getName(){
    return name;
}
void Player::PlacePieces(){

    for(int i = 0; i<getPieces().size();i++){

           Piece* ptr = getPieces().at(i);
          board->setField(ptr->getPosX(),ptr->getPosY(),ptr->getName());

    }


}
