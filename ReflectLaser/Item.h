#pragma once
#include "Block.h"

class Item :public Block {//���е��ߵĻ���
private:
	int angle;
public:
	Item(bool empty = true);
	Item(const Item& it);
	void rotate(bool isClock);//true��Ϊ˳ʱ����ת��false��Ϊ��ʱ��
	virtual string getImage()const;
};