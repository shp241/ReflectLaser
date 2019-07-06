#pragma once
#include "Block.h"

class Item :public Block {
private:
	bool isUsed;
	int angle;
public:
	Item(bool used);
	Item(const Item& it);
	void rotate(bool isClock);//true��Ϊ˳ʱ����ת��false��Ϊ��ʱ��
	virtual string getImage();
};