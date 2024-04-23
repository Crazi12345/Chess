#include "Knight.h"

Knight::Knight()
{

}

Knight::Knight(int posX, int posY, char type, char color)
{
    this->color = color;
    this->type = type;
    this->posX = posX;
    this->posY = posY;
}

char Knight::getType(){
    return type;
}
char Knight::getColor(){
    return color;
}
std::string Knight::getName(){
    std::string name = "";
            name += type;
            name += color;
    return name;
}



int Knight::getPosX(){
    return posX;
}
int Knight::getPosY(){
    return posY;
}
std::string Knight::getFullName(){
    return "Knight";
}

bool Knight::validMove(int posX, int posY){

    if(posX == this->getPosX()+2 && posY == this->getPosY()+1){
        return true;
    }
    else if(posX == this->getPosX()-2 && posY == this->getPosY()-1){
        return true;
    }
    else if(posX == this->getPosX()+2 && posY == this->getPosY()-1){
        return true;
    }
    else if(posX == this->getPosX()-2 && posY == this->getPosY()+1){
        return true;
    }
    else if(posX == this->getPosX()-1 && posY == this->getPosY()-2){
        return true;
    }
    else if(posX == this->getPosX()+1 && posY == this->getPosY()-2){
        return true;
    }
    else if(posX == this->getPosX()+1 && posY == this->getPosY()+2){
        return true;
    }
    else if(posX == this->getPosX()-1 && posY == this->getPosY()+2){
        return true;
    }
    else {return false;}

}

void Knight::setPosX(int value){
        posX = value;
}
void Knight::setPosY(int value){
        posY = value;
}
