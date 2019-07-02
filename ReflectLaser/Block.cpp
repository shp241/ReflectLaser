#include "Block.h"

Block::	Block(RelativePoint* p){
    this->p=p;
}

RelativePoint* Block::getPosition(){
    return this->p;
}

Block::bool isEmpty(){
    return true;
}

Block::bool canMove(){
    return false;
}

Block::void draw(){
    //
}
