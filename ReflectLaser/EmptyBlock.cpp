#include "EmptyBlock.h"

EmptyBlock::EmptyBlock(RelativePoint* p):Block(p){}

void EmptyBlock::draw(){
    //
}

Vector& EmptyBlock::operator[](int n){
    return vectors[n];
}

int getDirectionNumber(Direction d){
    switch(d){
    case UP:
        return 0;
    case UP_RIGHT:
        return 1;
    case RIGHT:
        return 2;
    case DOWN_RIGHT:
        return 3;
    case DOWN:
        return 4;
    case DOWN_LEFT:
        return 5;
    case LEFT:
        return 6;
    case UP_LEFT:
        return 7;
    }
    return 0;
}

void EmptyBlock::addVector(Vector* v){
    vectors[getDirectionNumber(*v->getDirection())]+=*v->getColour();
    lines[getDirectionNumber(*v->getDirection())%4]+=*v->getColour();
}

void EmptyBlock::clear(){
    for(int i=0;i<4;i++){
        vectors[i]=Colour::BLACK;
        Vectors[i+4]=Colour::BLACK;
        lines[i]=Colour::BLACK;
    }
}
