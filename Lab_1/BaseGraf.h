#pragma once
template<typename T>
class BaseGraf abstract
{
private:
public:
	virtual void add(T element) = 0;
	virtual T removeIndex(int nomer) = 0;
	virtual void removeElem(T element) = 0;
};

