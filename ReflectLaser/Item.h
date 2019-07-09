#pragma once
#include "Block.h"

class Item :public Block {//���е��ߵĻ���
private:
	int angle;
public:
	Item(RelativePoint* p, bool empty = true, int angle = 0);
	Item(const Item& it);
	void rotate(bool isClock);//true��Ϊ˳ʱ����ת��false��Ϊ��ʱ��
	int getAngle()const;
	void setAngle(int angle);
	virtual void draw()const;
	virtual list<Vector*> getLight(Vector* from);
	~Item();
};