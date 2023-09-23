#pragma once
template<typename T>
class BaseGraf abstract
{
private:
public:
	virtual void add(T element) = 0;
	virtual void removeElem(T element) = 0;
	virtual bool contains(T element) = 0;
	virtual void print() = 0;
};

