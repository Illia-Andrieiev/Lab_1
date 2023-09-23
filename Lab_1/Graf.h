#pragma once
#include "BaseGraf.h"
template<typename T>
class Graf : public BaseGraf<T>
{
private:
	T* vertexes;
	int vertexAmount;
	int edgeAmount;
public:
	void add(T element);
	T removeIndex(int nomer);
	void removeElem(T element);
};

