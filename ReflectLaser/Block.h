#pragma once
#include <list>
#include <iostream>
#include <string>
#include "RelativePoint.h"
#include "Vector.h"
using std::list;
using std::string;
using std::to_string;

class Block {//��һ��ͼ����
private:
	RelativePoint* p;//��ͼ����������
	bool empty;//ture���ʾ�õ�ͼ��Ϊ��
	bool moved;//ture���ʾ�õ�ͼ����ƶ�
public:
	Block(RelativePoint* p, bool empty = true, bool moved = false);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty()const;//�жϸõ�ͼ���Ƿ�Ϊ��
	bool canMove()const;//�жϸõ�ͼ���Ƿ���ƶ�
	virtual string getImage()const;//��ȡ�õ�ͼ���ϵ��ߵ�ͼƬ��
	virtual list<Vector*> getLight(Vector* from);
	virtual ~Block();
};
