#pragma once
#include <string>
#include "Button.h"
#include "RelativePoint.h"
#include "System.h"
using std::string;

class Block :public Button {//��һ��ͼ����
private:
	RelativePoint* p;//��ͼ����������
	bool empty;//ture���ʾ�õ�ͼ��Ϊ��
	bool moving;//ture���ʾ�õ�ͼ����ƶ�
public:
	Block(RelativePoint* p, bool empty = true, bool moving = false);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty()const;//�жϸõ�ͼ���Ƿ�Ϊ��
	bool canMove()const;//�жϸõ�ͼ���Ƿ����ƶ�
	virtual string getImage()const;//��ȡ�õ�ͼ���ϵ��ߵ�ͼƬ��
	virtual void role();
	virtual ~Block();
};
