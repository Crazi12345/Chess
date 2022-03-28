#include "Queen.h"

Queen::Queen()
{

}

Queen::Queen(int posX, int posY, char type, char color)
{
    this->color = color;
    this->type = type;
    this->posX = posX;
    this->posY = posY;
}

char Queen::getType(){
    return type;
}
char Queen::getColor(){
    return color;
}
std::string Queen::getName(){
    std::string name = "";
            name += type;
            name += color;
    return name;
}


int Queen::getPosX(){
    return posX;
}
int Queen::getPosY(){
    return posY;
}
std::string Queen::getFullName(){
    return "Queen";
}

bool Queen::validMove(int posX, int posY)
{
    int X = this->getPosX()-posX;
    int Y = posY-this->getPosY();

    if(X==0 && Y!=0){
        return true;
    }
    else if(X!=0 && Y==0){
        return true;
    }
    else{



        int X = (this->getPosX()-posX);
        X = X*X;
        int Y = (this->getPosY()-posY);
        if(X==Y){
            return true;
        }
        else {return false;}
    }
}
void Queen::setPosX(int value){
        posX = value;
}
void Queen::setPosY(int value){
        posY = value;
}
