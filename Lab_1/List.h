#pragma once
template<typename T>
class List abstract
{
private:
	int size;
public:
	bool isEmpty() abstract;
	bool contains(T element) abstract;
	int indexOf(T element) abstract;
	int size() abstract;
	void pushBack(T element) abstract;
	void pushIndex(T element, int index) abstract;
	void addAll(T* arr) abstract;
	void addAll(List<T> *other) abstract;
	void clear() abstract;
	void remove(T element) abstract;
	void set(T element, int index) abstract;
	T remove(int index) abstract;
	List<T>* clone() abstract;

};

