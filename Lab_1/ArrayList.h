#pragma once
#include <iostream>
#include "List.h"

template<typename T>
class ArrayList : public List<T>
{
private:
	int elementAmount = 0;
	int arraySize;
	T* array;
	void extendArray();
	void extendArray(int amount);
	void reduceArray();
public:
	ArrayList();
	ArrayList(T* elements, int size);
	~ArrayList();
	bool isEmpty();
	bool contains(T element);
	int indexOf(T element);
	int size();
	void pushBack(T element);
	void pushIndex(T element, int index);
	void addAll(T* arr, int size);
	void addAll(List<T>* other);
	void clear();
	void set(T element, int index);
	void print();
	T removeIndex(int index);
	T removeElem(T element);
	T get(int index);
	List<T>* clone();
};
