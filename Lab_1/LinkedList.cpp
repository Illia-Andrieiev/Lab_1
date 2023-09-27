#pragma once
#include "LinkedList.h"
// Constructors
template<typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
	elementAmount = 0;
}
template<typename T>
LinkedList<T>::LinkedList(T* elements, int size) {
	head = nullptr;
	tail = nullptr;
	elementAmount = 0;
	for (int i = 0; i < size; i++) {
		pushBack(elements[i]);
	}
}
// Destructor
template<typename T>
LinkedList<T>::~LinkedList() {
	clear();
}
// getters
template<typename T>
ListNode<T>* LinkedList<T>::getHead() {
	return head;
}
template<typename T>
ListNode<T>* LinkedList<T>::getTail() {
	return tail;
}
// Return first index of element. -1 if do not contain 
template<typename T>
int LinkedList<T>::indexOf(T element) {
	int position = 0;
	ListNode<T>* curr = head;
	while (curr != nullptr) {
		if (curr->data == element)
			return position;
		++position;
		curr = curr->next;
	}
	return -1;
}
// Return true, if List is empty
template<typename T>
bool LinkedList<T>::isEmpty() {
	return elementAmount == 0;
}
// Return true, if List contains Element. Type of Element must have overload "==" operator
template<typename T>
bool LinkedList<T>::contains(T element) {
	return indexOf(element) != -1;
};
// Return amount of cointained elements
template<typename T>
int LinkedList<T>::size() {
	return elementAmount;
};
// Add element in the end of array. Extend array if it necessary
template<typename T>
void LinkedList<T>::pushBack(T element) {
	if (head == nullptr) {
		head = new ListNode<T>(element, nullptr);
		tail = head;
	}
	else {
		ListNode<T>* newElem = new ListNode<T>(element, nullptr);
		tail->next = newElem;
		tail = tail->next;
	}
	++elementAmount;
};
// Add element at the index in List.
template<typename T>
void LinkedList<T>::pushIndex(T element, int index) {
	if (0 > index || index > elementAmount) // Check index
		return;
	ListNode<T>* curr = head;
	if (index == 0) {
		ListNode<T>* newElem = new ListNode<T>(element, head);
		head = newElem;
		++elementAmount;
	}
	else if (index == elementAmount) {
		pushBack(element);
	}
	else {
		for (int i = 1; i < index; i++) {
			curr = curr->next;
		}
		ListNode<T>* newElem = new ListNode<T>(element, curr->next);
		curr->next = newElem;
		++elementAmount;
	}

};
// Add array of elements in the end of list
template<typename T>
void LinkedList<T>::addAll(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		pushBack(arr[i]);
	}
};
// Add other List of elements in the end of This list
template<typename T>
void LinkedList<T>::addAll(List<T>* other) {
	if (other == nullptr)
		return;
	for (int i = 0; i < other->size(); i++) {
		pushBack(other->get(i));
	}
};
// Set new value at index
template<typename T>
void LinkedList<T>::set(T element, int index) {
	if (index < 0 || index >= elementAmount)
		return;
	ListNode<T>* curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	curr->data = element;
};
// Delete Element from List by index
template<typename T>
T LinkedList<T>::removeIndex(int index) {
	if (index < 0 || index >= elementAmount)
		return 0;
	if (index == 0) {
		ListNode<T>* res = head;
		head = head->next;
		--elementAmount;
		return res->data;
	}
	ListNode<T>* res = head->next;
	ListNode<T>* prev = head;
	for (int i = 1; i < index; i++) {
		res = res->next;
		prev = prev->next;
	}
	prev->next = res->next;
	res->next = nullptr;
	--elementAmount;
	return res->data;;
}
// Remove element
template<typename T>
T LinkedList<T>::removeElem(T element) {
	return removeIndex(indexOf(element));
}
// Return element by index
template<typename T>
T LinkedList<T>::get(int index) {
	if (index < 0 || index >= elementAmount)
		return 0;
	ListNode<T>* curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}
// Clear List
template<typename T>
void LinkedList<T>::clear() {
	elementAmount = 0;
	if (head == nullptr)
		return;
	ListNode<T>* curr = head->next;
	while (true) {
		delete head;
		head = curr;
		if (head == nullptr)
			return;
		curr = head->next;
	}
}
// Return copy of this list
template<typename T>
List<T>* LinkedList<T>::clone() {
	List<T>* res = new LinkedList<T>();
	res->addAll(this);
	return res;
};
// Print LinkedList in console
template<typename T>
void LinkedList<T>::print() {
	ListNode<T>* curr = head;
	while (curr != nullptr) {
		std::cout << curr->data << "    ";
		curr = curr->next;
	}
	std::cout << std::endl;
}