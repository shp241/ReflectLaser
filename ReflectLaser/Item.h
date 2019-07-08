#pragma once
#include "Block.h"

class Item :public Block {//���е��ߵĻ���
private:
	int angle;
public:
	Item(RelativePoint* p, bool empty = true, int angle = 0);
	Item(const Item& it);
	Item(const Item& it, RelativePoint* p);
	void rotate(bool isClock);//true��Ϊ˳ʱ����ת��false��Ϊ��ʱ��
	int getAngle()const;
	void setAngle(int angle);
	virtual string getImage()const;
	virtual void role();
	~Item();
};