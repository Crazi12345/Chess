#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
class Rook: public Piece
{
public:
    Rook();
    Rook(int posX, int posY,char type, char color );
    virtual char getType() override;
    virtual char getColor() override;
    virtual std::string getName() override;
    virtual int getPosX()override;
    virtual int getPosY()override;
    virtual std::string getFullName() override;
    virtual bool validMove(int posX, int posY) override;
    virtual void setPosX(int val)override;
    virtual void setPosY(int val)override;
private:
    char type;
    char color;
    int posX;
    int posY;
};

#endif // ROOK_H
