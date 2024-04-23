#include "King.h"



King::King(int posX, int posY, char type, char color)
{
    this->color = color;
    this->type = type;
    this->posX = posX;
    this-> posY = posY;
}

char King::getType(){
    return type;
}
char King::getColor(){
    return color;
}
std::string King::getName(){
    std::string name = "";
            name += type;
            name += color;
    return name;
}


int King::getPosX(){
    return posX;
}
int King::getPosY(){
    return posY;
}
std::string King::getFullName(){
    return "King";
}

bool King::validMove(int posX, int posY)
{
  if(posX == this->getPosX()+1 && posY == this->getPosY()+1)
  {
      return true;
  }
  else if(posX == this->getPosX()-1 && posY == this->getPosY()-1)
  {
      return true;
  }
  else if(posX == this->getPosX() && posY == this->getPosY()-1)
  {
      return true;
  }
  else if(posX == this->getPosX()-1 && posY == this->getPosY())
  {
      return true;
  }
  else if(posX == this->getPosX()+1 && posY == this->getPosY())
  {
      return true;
  }
  else if(posX == this->getPosX() && posY == this->getPosY()+1)
  {
      return true;
  }
  else{
      return false;
  }
}

void King::setPosX(int value){
        posX = value;
}
void King::setPosY(int value){
        posY = value;
}
