#pragma once
#include "ArrayList.h"
#include "List.h"
//******************************************************************
/*
							PRIVATE METHODS
*/
//******************************************************************
// Increases array size on 20
template<typename T>
void ArrayList<T>::extendArray() {
	T* newArray = new T[arraySize + 20];
	for (int i = 0; i < elementAmount; i++) {
		newArray[i] = array[i];
	}
	arraySize += 20;
	delete[] array;
	array = newArray;
};
// Increases array size on amount
template<typename T>
void ArrayList<T>::extendArray(int amount) {
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
template<typename T>
void ArrayList<T>::reduceArray() {
	T* newArray = new T[arraySize - 20];
	for (int i = 0; i < elementAmount; i++) {
		newArray[i] = array[i];
	}
	arraySize -= 20;
	delete[] array;
	array = newArray;
}
//******************************************************************
/*
							PUBLIC METHODS
*/
//******************************************************************
// Constructors
template<typename T>
ArrayList<T>::ArrayList() {
	elementAmount = 0;
	arraySize = 20;
	array = new T[20];
};
template<typename T>
ArrayList<T>::ArrayList(T* elements, int size) {
	if (size < 0)
		size -= size * 2;
	this->elementAmount = size;
	arraySize = ((int)size / 20 + 1) * 20;
	array = new T[arraySize];
	addAll(elements, size);
};
// Destructor
template<typename T>
ArrayList<T>::~ArrayList() {
	delete[] array;
};
// Return true, if ArrayList is empty
template<typename T>
bool ArrayList<T>::isEmpty() {
	if (elementAmount == 0)
		return true;
	return false;
};
// Return amount of cointained elements
template<typename T>
int ArrayList<T>::size() {
	return elementAmount;
};
// Return true, if ArrayList contains Element. Type of Element must have overload "==" operator
template<typename T>
bool ArrayList<T>::contains(T element) {
	for (int i = 0; i < elementAmount; i++) {
		if (array[i] == element)
			return true;
	}
	return false;
};
// Return first index of element. -1 if do not contain 
template<typename T>
int ArrayList<T>::indexOf(T element) {
	for (int i = 0; i < elementAmount; i++) {
		if (array[i] == element)
			return i;
	}
	return -1;
};
// Add element in the end of array. Extend array if it necessary
template<typename T>
void ArrayList<T>::pushBack(T element) {
	if (elementAmount == arraySize)
		extendArray();
	array[elementAmount] = element;
	++elementAmount;

};
// Add element at the index in array. Extend array if it necessary
template<typename T>
void ArrayList<T>::pushIndex(T element, int index) {
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
template<typename T>
void ArrayList<T>::addAll(T* arr, int size) {
	if (size < 0)
		return;
	if ((arraySize - elementAmount) < size) {
		extendArray(size);
	}
	for (int i = 0; i < size; i++) {
		array[elementAmount++] = arr[i];
	}
};
// Add other List of elements in the end of This list
template<typename T>
void ArrayList<T>::addAll(List<T>* other) {
	if (other == nullptr)
		return;
	if ((arraySize - elementAmount) < other->size()) {
		extendArray(other->size());
	}
	for (int i = 0; i < other->size(); i++) {
		array[elementAmount++] = other->get(i);
	}
};
// Clear List
template<typename T>
void ArrayList<T>::clear() {
	delete[] array;
	elementAmount = 0;
	arraySize = 20;
	array = new T[20];
};
// Set new value at index
template<typename T>
void ArrayList<T>::set(T element, int index) {
	if (index < 0 || index >= elementAmount)
		return;
	array[index] = element;
};
// Print ArrayList in console
template<typename T>
void ArrayList<T>::print() {
	for (int i = 0; i < elementAmount; i++) {
		std::cout << array[i] << "    ";
	}
	std::cout << std::endl;
};
// Remove element by index. Reduce array if necessary
template<typename T>
T ArrayList<T>::removeIndex(int index) {
	if (index < 0 || index >= elementAmount)
		return 0;
	T res = array[index];
	for (int i = index; i < elementAmount - 1; i++) { // Shift array elements
		array[i] = array[i + 1];
	}
	--elementAmount;
	//array[--elementAmount] = 0;
	if (arraySize - elementAmount > 20)
		reduceArray();
	return res;
};
// Remove first element. Reduce array if necessary
template<typename T>
T ArrayList<T>::removeElem(T element) {
	return removeIndex(indexOf(element));
}
// Return element by index. 0 if index out of borders
template<typename T>
T ArrayList<T>::get(int index) {
	if (index < 0 || index >= elementAmount)
		return 0;
	return array[index];
}
// Return copy of this list
template<typename T>
ArrayList<T>* ArrayList<T>::clone(){
	ArrayList<T>* res = new ArrayList<T>();
	res->addAll(this);
	return res;
};