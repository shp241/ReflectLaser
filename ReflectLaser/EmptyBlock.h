#pragma once
#include "Block.h"
#include "Colour.h"
#include "Vector.h"

class EmptyBlock :public Block {//���ڱ�ʾ�յĵ�ͼ��
private:
	Colour vectors[8];//���8���������������ɫ
public:
	EmptyBlock(RelativePoint* p);
	string getImage();
	void addVector(Vector* v);//��յ�ͼ�����������
	void clear();//�����������
	Colour& operator[](int n);//��ȡ�������е�Ԫ��
	~EmptyBlock();
};
