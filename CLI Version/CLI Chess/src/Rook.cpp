#include "Rook.h"

Rook::Rook()
{

}

Rook::Rook(int posX, int posY, char type, char color)
{
    this->color = color;
    this->type = type;
    this->posX = posX;
    this->posY = posY;
}

char Rook::getType(){
    return type;
}
char Rook::getColor(){
    return color;
}
std::string Rook::getName(){
    std::string name = "";
            name += type;
            name += color;
    return name;
}


int Rook::getPosX(){
    return posX;
}

int Rook::getPosY(){
    return posY;
}

std::string Rook::getFullName(){
    return "Rook";
}

bool Rook::validMove(int posX, int posY){

int X = this->getPosX()-posX;
int Y = posY-this->getPosY();

if(X==0 && Y!=0){
    return true;
}
else if(X!=0 && Y==0){
    return true;
}
else{

return false;
}
}

void Rook::setPosX(int value){
        posX = value;
}
void Rook::setPosY(int value){
        posY = value;
}
