#pragma once
#include "Colour.h"
#include "RelativePoint.h"

class Vector {//�����࣬���ڱ�ǿշ����ڵĹ��߷�����ɫ
private:
	Colour* c;//��������ɫ
	Direction* d;//�����ķ���
	RelativePoint* p;
public:
	Vector(Direction* d, Colour* c, RelativePoint* p);
	Vector(const Vector& v, RelativePoint* p);
	Direction* getDirection()const;
	Colour* getColour()const;
	RelativePoint* getPosition()const;
	bool operator==(const Vector& v)const;
	~Vector();
};
