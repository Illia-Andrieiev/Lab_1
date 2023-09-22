#pragma once
#include "List.h"
template<typename T>
class ArrayList : public List
{
private:
	int size;
	int arraySize;
	T* array;
	// Increases array size on 20
	void extendArray() {
		T* newArray = new T[arraySize + 20];
		for (int i = 0; i < size; i++) {
			newArray[i] = array[i];
		}
		arraySize += 20;
		delete[] array;
		array = newArray;
	}
public:
	// Constructors
	ArrayList() {
		size = 0;
		arraySize = 20;
		array = new T[20];
	}
	ArrayList(T* elements, int size) {
		this->size = size;
		arraySize = ((int)size/20 + 1) * 20;
		array = new T[arraySize];
		addAll(elements, size);
	}
	// Destructor
	~ArrayList() {
		delete[] array;
	}
	// Return true, if ArrayList is empty
	bool isEmpty() {
		if (size == 0)
			return true;
		return false;
	}
	// Return true, if ArrayList contains Element. Type of Element must have overload "==" operator
	bool contains(T element) {
		for (int i = 0; i < size; i++) {
			if (array[i] == element)
				return true;
		}
		return false;
	};
	// Return first index of element. -1 if do not contain 
	int indexOf(T element) {
		for (int i = 0; i < size; i++) {
			if (array[i] == element)
				return i;
		}
		return -1;
	};
	// Return amount of cointained elements
	int size() {
		return size;
	};
	// Add element in the end of array. Extend array if it necessary
	void pushBack(T element) {
		if (size == arraySize)
			extendArray();
		array[size] = element;
		++size;

	};
	void pushIndex(T element, int index) {};
	void addAll(T* arr, int size) {};
	void addAll(List<T>* other) {};
	void clear() {};
	void remove(T element) {};
	void set(T element, int index) {};
	T remove(int index) {};
	List<T>* clone() {};

};

