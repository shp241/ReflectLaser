<<<<<<< HEAD
#pragma once
#include <iostream>
#include <string>
#include "Button.h"
#include "RelativePoint.h"
#include "System.h"
using std::string;
using std::to_string;

class Block :public Button {//��һ��ͼ����
private:
	RelativePoint* p;//��ͼ����������
	bool empty;//ture���ʾ�õ�ͼ��Ϊ��
public:
	Block(RelativePoint* p, bool empty = true);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty()const;//�жϸõ�ͼ���Ƿ�Ϊ��
	virtual string getImage()const;//��ȡ�õ�ͼ���ϵ��ߵ�ͼƬ��
	virtual void role();
	virtual ~Block();
};
=======
#pragma once
#include <iostream>
#include <string>
#include "Button.h"
#include "RelativePoint.h"
#include "System.h"
using std::string;
using std::to_string;

class Block :public Button {//��һ��ͼ����
private:
	RelativePoint* p;//��ͼ����������
	bool empty;//ture���ʾ�õ�ͼ��Ϊ��
public:
	Block(RelativePoint* p, bool empty = true);
	Block(const Block& b);
	RelativePoint* getPosition()const;
	void setPosition(RelativePoint* p);
	bool isEmpty()const;//�жϸõ�ͼ���Ƿ�Ϊ��
	virtual string getImage()const;//��ȡ�õ�ͼ���ϵ��ߵ�ͼƬ��
	virtual void role();
	virtual ~Block();
};
>>>>>>> 80cd96100565c9010b616e60b123563c5125961d
