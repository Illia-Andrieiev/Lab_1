#pragma once
#include <iostream>
#include "List.h"
template<typename T>
class ArrayList : public List<T>
{
private:
	int elementAmount;
	int arraySize;
	T* array;
	// Increases array size on 20
	void extendArray() {
		T* newArray = new T[arraySize + 20];
		for (int i = 0; i < elementAmount; i++) {
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
		for (int i = 0; i < elementAmount; i++) {
			newArray[i] = array[i];
		}
		arraySize += amount;
		delete[] array;
		array = newArray;
	};
	// Reduce array size on 20
	void reduceArray() {
		T* newArray = new T[arraySize - 20];
		for (int i = 0; i < elementAmount; i++) {
			newArray[i] = array[i];
		}
		arraySize -= 20;
		delete[] array;
		array = newArray;
	}
public:
	// Constructors
	ArrayList() {
		elementAmount = 0;
		arraySize = 20;
		array = new T[20];
	};
	ArrayList(T* elements, int size) {
		this->elementAmount = size;
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
		if (elementAmount == 0)
			return true;
		return false;
	};
	// Return true, if ArrayList contains Element. Type of Element must have overload "==" operator
	bool contains(T element) {
		for (int i = 0; i < elementAmount; i++) {
			if (array[i] == element)
				return true;
		}
		return false;
	};
	// Return first index of element. -1 if do not contain 
	int indexOf(T element) {
		for (int i = 0; i < elementAmount; i++) {
			if (array[i] == element)
				return i;
		}
		return -1;
	};
	// Return amount of cointained elements
	int size() {
		return elementAmount;
	};
	// Add element in the end of array. Extend array if it necessary
	void pushBack(T element) {
		if (elementAmount == arraySize)
			extendArray();
		array[elementAmount] = element;
		++elementAmount;

	};
	// Add element at the index in array. Extend array if it necessary
	void pushIndex(T element, int index) {
		if (0 > index || index > elementAmount) // Check index
			return;
		if (elementAmount == arraySize)
			extendArray();
		++elementAmount;
		T temp = array[index];
		for (int i = index; i < elementAmount; i++) { // Shift array elements
			array[i] = element;
			element = temp;
			if (i != elementAmount - 1)
				temp = array[i + 1];
		}

	};
	// Add array of elements in the end of list
	void addAll(T* arr, int size) {
		if ((arraySize - elementAmount) < size) {
			extendArray(size);
		}
		for (int i = 0; i < size; i++) {
			array[elementAmount++] = arr[i];
		}
	};
	// Add other List of elements in the end of This list
	void addAll(List<T>* other) {
		if ((arraySize - elementAmount) < other->size()) {
			extendArray(other->size());
		}
		for (int i = 0; i < other->size(); i++) {
			array[elementAmount++] = other->get(i);
		}
	};
	// Clear List
	void clear() {
		delete[] array;
		elementAmount = 0;
		arraySize = 20;
		array = new T[20];
	};
	// Set new value at index
	void set(T element, int index) {
		if (index < 0 || index >= elementAmount)
			return;
		array[index] = element;
	};
	// Print ArrayList in console
	void print() {
		for (int i = 0; i < elementAmount; i++) {
			std::cout << array[i] << "\t";
		}
	};
	// Remove element by index. Reduce array if necessary
	T removeIndex(int index) {
		if (index < 0 || index >= elementAmount)
			return 0;
		T res = array[index];
		for (int i = index; i < elementAmount - 1; i++) { // Shift array elements
			array[i] = array[i + 1];
		}
		array[--elementAmount] = 0;
		if (arraySize - elementAmount > 20)
			reduceArray();
		return res;
	};
	// Remove first element. Reduce array if necessary
	T removeElem(T element) {
		return removeIndex(indexOf(element));
	}
	// Return element by index
	T get(int index) {
		if (index < 0 || index >= elementAmount)
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
