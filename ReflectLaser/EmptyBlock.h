#pragma once
#include "Colour.h"
#include "Block.h"

class EmptyBlock:public Block {
private:
	Colour lines={Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK};
public:
    Colour vectors[8]={Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK,Colour::BLACK};
	EmptyBlock(RelativePoint* p):Block(p);
    void draw();
    Vector& operator[](int n);
    void addVector(Vector* v);
    void clear();
};
