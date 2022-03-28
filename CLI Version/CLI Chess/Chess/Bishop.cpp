#include "Bishop.h"

Bishop::Bishop()
{

}

Bishop::Bishop(int posX, int posY, char type, char color)
{

    this->color = color;
    this->type = type;
    this->posX = posX;
    this-> posY = posY;
}

char Bishop::getType(){
    return type;
}
char Bishop::getColor(){
    return color;
}
std::string Bishop::getName(){
    std::string name = "";
            name += type;
            name += color;
    return name;
}
int Bishop::getPosX(){
    return posX;
}
int Bishop::getPosY(){
    return posY;
}
std::string Bishop::getFullName(){
    return "Bishop";
}

bool Bishop::validMove(int posX, int posY)
{
  int X = (this->getPosX()-posX);
  X = X*X;
  int Y = (this->getPosY()-posY);
  Y=Y*Y;

  if(X==Y){

      return true;
  }
  else {return false;}
}

void Bishop::setPosX(int value){
        posX = value;
}
void Bishop::setPosY(int value){
    posY = value;
}


