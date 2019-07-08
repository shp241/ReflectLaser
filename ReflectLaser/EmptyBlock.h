#pragma once
#include "Block.h"
#include "Vector.h"

class EmptyBlock :public Block {//用于表示空的地图块
private:
	Colour vectors[8];//存放8个方向的向量的颜色
public:
	EmptyBlock(RelativePoint* p);
	virtual string getImage()const;
	void addVector(Vector* v);//向空地图块中添加向量
	void clear();//清空所有向量
	Colour& operator[](int n);//获取向量组中的元素
	Colour getVectorColour(int n)const;//获取向量组中的元素
	virtual ~EmptyBlock();
};
