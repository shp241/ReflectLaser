<<<<<<< HEAD
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
=======
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
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
};