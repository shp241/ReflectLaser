#pragma once
#include "Colour.h"
#include "Point.h"

class Vector {//�����࣬���ڱ�ǿշ����ڵĹ��߷�����ɫ
private:
	Colour* c;//��������ɫ
	Direction* d;//�����ķ���
public:
	Vector(Direction* d, Colour* c);
	Direction* getDirection()const;
	Colour* getColour()const;
	~Vector();
};
