#pragma once
#include <iostream>
#include "List.h"
template<typename T>
class ArrayList : public List<T>
{
private:
	int elementEmount;
	int arraySize;
	T* array;
	// Increases array size on 20
	void extendArray() {
		T* newArray = new T[arraySize + 20];
		for (int i = 0; i < elementEmount; i++) {
			newArray[i] = array[i];
		}
		arraySize += 20;
		delete[] array;
		array = newArray;
	};
	// Increases array size on amount
	void extendArray(int amount) {
		amount = amount - amount % 20 + 20;
		T* newArray = new T[arraySize + amount];
		for (int i = 0; i < elementEmount; i++) {
			newArray[i] = array[i];
		}
		arraySize += amount;
		delete[] array;
		array = newArray;
	};
	// Reduce array size on 20
	void reduceArray() {
		T* newArray = new T[arraySize - 20];
		for (int i = 0; i < elementEmount; i++) {
			newArray[i] = array[i];
		}
		arraySize -= 20;
		delete[] array;
		array = newArray;
	}
public:
	// Constructors
	ArrayList() {
		elementEmount = 0;
		arraySize = 20;
		array = new T[20];
	};
	ArrayList(T* elements, int size) {
		this->elementEmount = size;
		arraySize = ((int)size / 20 + 1) * 20;
		array = new T[arraySize];
		addAll(elements, size);
	};
	// Destructor
	~ArrayList() {
		delete[] array;
	};
	// Return true, if ArrayList is empty
	bool isEmpty() {
		if (elementEmount == 0)
			return true;
		return false;
	};
	// Return true, if ArrayList contains Element. Type of Element must have overload "==" operator
	bool contains(T element) {
		for (int i = 0; i < elementEmount; i++) {
			if (array[i] == element)
				return true;
		}
		return false;
	};
	// Return first index of element. -1 if do not contain 
	int indexOf(T element) {
		for (int i = 0; i < elementEmount; i++) {
			if (array[i] == element)
				return i;
		}
		return -1;
	};
	// Return amount of cointained elements
	int size() {
		return elementEmount;
	};
	// Add element in the end of array. Extend array if it necessary
	void pushBack(T element) {
		if (elementEmount == arraySize)
			extendArray();
		array[elementEmount] = element;
		++elementEmount;

	};
	// Add element at the index in array. Extend array if it necessary
	void pushIndex(T element, int index) {
		if (0 > index || index > elementEmount) // Check index
			return;
		if (elementEmount == arraySize)
			extendArray();
		++elementEmount;
		T temp = array[index];
		for (int i = index; i < elementEmount; i++) { // Shift array elements
			array[i] = element;
			element = temp;
			if (i != elementEmount - 1)
				temp = array[i + 1];
		}

	};
	// Add array of elements in the end of list
	void addAll(T* arr, int size) {
		if ((arraySize - elementEmount) < size) {
			extendArray(size);
		}
		for (int i = 0; i < size; i++) {
			array[elementEmount++] = arr[i];
		}
	};
	// Add other List of elements in the end of This list
	void addAll(List<T>* other) {
		if ((arraySize - elementEmount) < other->size()) {
			extendArray(other->size());
		}
		for (int i = 0; i < other->size(); i++) {
			array[elementEmount++] = other->get(i);
		}
	};
	// Clear List
	void clear() {
		delete[] array;
		elementEmount = 0;
		arraySize = 20;
		array = new T[20];
	};
	// Set new value at index
	void set(T element, int index) {
		if (index < 0 || index >= elementEmount)
			return;
		array[index] = element;
	};
	// Print ArrayList in console
	void print() {
		for (int i = 0; i < elementEmount; i++) {
			std::cout << array[i] << "\t";
		}
	};
	// Remove element by index. Reduce array if necessary
	T remove(int index) {
		if (index < 0 || index >= elementEmount)
			return 0;
		T res = array[index];
		for (int i = index; i < elementEmount - 1; i++) { // Shift array elements
			array[i] = array[i + 1];
		}
		if (arraySize - elementEmount > 20)
			reduceArray();
		return res;
	};
	// Return element by index
	T get(int index) {
		if (index < 0 || index >= elementEmount)
			return 0;
		return array[index];
	}
	// Return copy of this list
	List<T>* clone(List<T>* other) {
		List<T>* res = new ArrayList<T>();
		res->addAll(other);
		return res;
	};
};
