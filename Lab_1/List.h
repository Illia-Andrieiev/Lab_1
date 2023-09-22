#pragma once
template<typename T>
class List abstract
{
private:
	int elementAmount;
public:
	virtual bool isEmpty() abstract;
	virtual bool contains(T element) abstract;
	virtual int indexOf(T element) abstract;
	virtual int size() abstract;
	virtual void pushBack(T element) abstract;
	virtual void pushIndex(T element, int index) abstract;
	virtual void addAll(T* arr, int size) abstract;
	virtual void addAll(List<T> *other) abstract;
	virtual void clear() abstract;
	virtual void set(T element, int index) abstract;
	virtual void print() abstract;
	virtual T removeIndex(int index) abstract;
	virtual T removeElem(T element) abstract;
	virtual T get(int index) abstract;
	virtual List<T>* clone(List<T>* other) abstract;

};

