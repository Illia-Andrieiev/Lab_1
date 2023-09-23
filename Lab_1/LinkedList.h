#pragma once
#include <iostream>
#include "List.h"
#include "ListNode.cpp"
template<typename T>
class LinkedList : public List<T>
{
private:
	int elementAmount;
	ListNode<T>* head;
	ListNode<T>* tail;
public:
	// Constructors
	LinkedList();
	LinkedList(T* elements, int size);
	~LinkedList();
	ListNode<T>* getHead();
	ListNode<T>* getTail();
	int indexOf(T element);
	bool isEmpty();
	bool contains(T element);
	int size();
	void pushBack(T element);
	void pushIndex(T element, int index);
	void addAll(T* arr, int size);
	void addAll(List<T>* other);
	void set(T element, int index);
	T removeIndex(int index);
	T removeElem(T element);
	T get(int index);
	void clear();
	List<T>* clone();
	void print();
};

