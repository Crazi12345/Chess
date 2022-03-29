//
// Created by patri on 19-11-2021.
//

#include "Parser.h"
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <limits>
#include <map>
using namespace std;


Parser::Parser(){

}
Parser::Parser(Board* b) {
    board = b;
    letter.insert(pair<char, int>('a', 1));
    letter.insert(pair<char, int>('b', 2));
    letter.insert(pair<char, int>('c', 3));
    letter.insert(pair<char, int>('d', 4));
    letter.insert(pair<char, int>('e', 5));
    letter.insert(pair<char, int>('f', 6));
    letter.insert(pair<char, int>('g', 7));
    letter.insert(pair<char, int>('h', 8));

}

void Parser::Command(Player* c,Player* a) {
    current = c;
    alternate = a;
    cout << "\nPlease Input a Command:";
    words.clear();
    string command;
    getline(cin, command);
    string token;
    stringstream checker(command);

    while (getline(checker, token, ' ')) {
        words.push_back(token);
    }
    if(words.size()>0){
           wordOne =words.at(0) ;
           }
    if(words.size()>1){
         wordTwo=words.at(1);
    }
    if(words.size()>2){
          wordThree=words.at(2);
    }
try {
    if (wordOne == "select" && words.size() > 1) {
        selectCommand();

        return;
    } else if (words.at(0) == "move" && words.size() > 2) {
         moveCommand();
    } else if (words.at(0) == "help" && words.size() > 0) {
        helpCommand();
    } else {
        cout << "i dont understand" << endl;
        Command(current,alternate);

    }
}
catch (exception e){
    Command(current,alternate);
}


}


void Parser::helpCommand() {
    cout << endl;
    cout << "select" << "  " << "letter posistion" << "  " << "number posistion" << endl;
    cout << "move" << "  " << "a1" << " " << "a1" << endl;


}

void Parser::selectCommand() {
    int patterns[22][2]={{1,0},{1,1},
                         {0,-1},{1,-1},
                         {-1,0},{-1,1},
                         {0,1},{-1,-1},
                         {-1,2},{-2,1},
                         {1,2},{2,1},
                         {-1,-2},{-2,-1},
                         {1,-2},{2,-1},
                         {-1,0},{1,0},
                         {-1,1},{1,-1},
                         {-1,-1},{1,1}};
         auto key = letter.find(wordTwo.at(0));
         int y = key->second-1;
         int a  = static_cast<int>(wordTwo.at(1));
         int x = (AsciiToInt(a)-1);
         Piece* piece  =  Find(x,y,current);


         int start;
         int stop;
         int step;
         int limit=8;

         switch (piece->getType()) {
         case 'P':
              if(piece->getColor()== 'b'){
                  start = 17;
                  stop = 21;
                  step = 2;
                  if(piece->getPosX()==1){
                      limit = 2;
                  }
                  else{
                      limit = 1;
                  }
              }
              else {
                  start = 16;
                  stop = 21;
                  step = 2;
                  if(piece->getPosX() == 6){
                      limit = 2;

                  }
                  else {
                      limit = 1;
                  }
              }
             break;
         case 'N':
             start = 8;
             stop = 15;
             step =1;
             limit=1;

             break;
         case 'K':
             start = 0;
             stop = 8;
             step =1;
             limit=1;
             break;
         case 'Q':
             start = 0;
             stop = 8;
             step =1;
             break;
         case 'R':
             start = 0;
             stop = 7;
             step = 2;
             break;
         case 'B':
             start = 1;
             stop = 8;
             step = 2;
             limit = 7;
             break;

         }

         int posX;
         int posY;
         int id=0;
         string s = "X";
         for(int i =0+start; i<0+stop;i+=step){
             id++;
              posX = x;
              posY = y;
              posX += patterns[i][0];
              posY += patterns[i][1];
             for(int j = 0; j<limit;j++){
               if(Find(posX,posY,current)!=nullptr){
                   j++;
                break;}
                 if(posX>7||posY>7 || posX<0||posY<0){break;}

                 if(Find(posX,posY,alternate)!=nullptr){
                    string s(1,Find(posX,posY,alternate)->getType());
                    if(piece->getType()=='P'){
                        if (Find(posX,posY,alternate)!=nullptr && id > 1){
                              board->setField(posX,posY,s+"*");
                        }
                        else {
                            break;
                        }
                    }
                    cout<<"READ"<<endl;
                    board->setField(posX,posY,s+"*");

                    break;
                 }
                 else{

                  //s = (1,Find(posX,posY,alternate)->getType());
                     if(piece->getType()=='P'&&id>1){
                         if (Find(posX,posY,alternate)!=nullptr ){
                               board->setField(posX,posY,s+"*");
                         }
                         else {
                             break;
                         }
                     }

                    board->setField(posX,posY,"**");
                 }
                  //cout <<id<<": "<< posX <<" "<< posY << endl;
                 posX += patterns[i][0];
                 posY += patterns[i][1];
                 // simple step by step
                /* board->PrettyPrint();
                 board->resetBoard();
                 current->PlacePieces();
                 cin.get();*/

             }
         }


       endCommand();
         return;

   }


void Parser::moveCommand(){

    auto key = letter.find(wordTwo.at(0));
    int y = key->second-1;

    int a  = static_cast<int>(wordTwo.at(1));
    int x = (AsciiToInt(a)-1);

    auto secondKey = letter.find(wordThree.at(0));
    int secondY = secondKey->second-1;

    int b  = static_cast<int>(wordThree.at(1));
    int secondX = (AsciiToInt(b)-1);

    Piece* selected = Find(x,y,current);
if(selected->validMove(secondX,secondY)==true){
   selected->setPosX(secondX);
   selected->setPosY(secondY);
}
else {
    cout << "Unmoveable" << endl;
    Command(current,alternate);
}

}


Piece* Parser::Find(int x, int y,Player* player){

    for(int i = 0; i<7;i++){
           for(int j =0; j<7;j++){
               for(int k = 0; k<player->getPieces().size();k++){
                  if(player->getPieces().at(k)->getPosX()==x && player->getPieces().at(k)->getPosY()==y){

                      return player->getPieces().at(k);
                  }

               }
           }
       }

    Piece* tmp=nullptr;
    return tmp;



}

    



void Parser::printWord() {

    for (int i = 0; i < words.size(); i++) {
        cout << words.at(i) << endl;
    }
}

int Parser::AsciiToInt(int ascii) {

    switch(ascii){
        case 49:
            return 1;
        case 50:
            return 2;
        case 51:
            return 3;
        case 52:
            return 4;
        case 53:
            return 5;
        case 54:
            return 6;
        case 55:
            return 7;
        case 56:
            return 8;
        default:
            return 0;


    }


}


void Parser::endCommand(){
    board->PrettyPrint();
    board->resetBoard();
    current->PlacePieces();
    alternate->PlacePieces();
    Command(current,alternate);
    
    
    
}
