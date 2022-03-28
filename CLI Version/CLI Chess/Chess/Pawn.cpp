#include "Pawn.h"

Pawn::Pawn(int posX, int posY, char type,char color)
{
    this->color = color;
    this->type = type;
    this->posX = posX;
    this->posY = posY;
}

char Pawn::getType(){
    return type;
}
char Pawn::getColor(){
    return color;
}
std::string Pawn::getName(){
    std::string name = "";
            name += type;
            name += color;
    return name;
}


int Pawn::getPosX(){
    return posX;
}

int Pawn::getPosY(){
    return posY;
}
std::string Pawn::getFullName(){
    return "Pawn";
}

bool Pawn::validMove(int posX, int posY)
{
      if(this->getColor()=='w'){
          if(posY == this->getPosY()+1){
              return true;
          }
          else{
              return false;
          }
      }
      else {
          if(posY == this->getPosY()-1){
              return true;
          }
          else{
              return false;
          }
      }
}
void Pawn::setPosX(int value){
        posX = value;
}
void Pawn::setPosY(int value){
        posY = value;
}
