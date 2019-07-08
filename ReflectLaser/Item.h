#pragma once
#include "Block.h"

class Item :public Block {//���е��ߵĻ���
private:
	int angle;
public:
	Item(RelativePoint* p, bool empty = true);
	Item(const Item& it);
	Item(const Item& it, RelativePoint* p);
	void rotate(bool isClock);//true��Ϊ˳ʱ����ת��false��Ϊ��ʱ��
	virtual string getImage()const;
};