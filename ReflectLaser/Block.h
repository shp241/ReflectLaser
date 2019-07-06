#pragma once
#include "RelativePoint.h"
#include <string>
using std::string;

class Block {//��һ��ͼ����
private:
	RelativePoint* p;//��ͼ����������
	bool empty;//ture���ʾ�õ�ͼ��Ϊ��
	bool moving;//ture���ʾ�õ�ͼ����ƶ�
public:
	Block(RelativePoint* p, bool empty = true, bool moving = false);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty();//�жϸõ�ͼ���Ƿ�Ϊ��
	bool canMove();//�жϸõ�ͼ���Ƿ����ƶ�
	virtual string getImage();//��ȡ�õ�ͼ���ϵ��ߵ�ͼƬ��
	virtual ~Block();
};
