#pragma once
#include "BaseGraf.h"
#include"List.h"
template<typename T>
class BaseTree : public BaseGraf<T>
{
private:
	int elementAmount = 0;
public:
	virtual void addAll(List<T>* list) = 0;
	virtual void add(T element) = 0;
	virtual void removeElem(T element) = 0;
	virtual bool contains(T element) = 0;
	virtual void print() = 0;
};

