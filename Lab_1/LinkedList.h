#pragma once
#include "List.h"
#include "ListNode.h"
template<typename T>
class LinkedList : public List<T>
{
private:
	int elementAmount;
	ListNode<T>* head;
	ListNode<T>* tail;
public:
	// Constructors
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		elementAmount = 0;
	}
	LinkedList(T* elements, int size) {
		head = nullptr;
		tail = nullptr;
		elementAmount = 0;
		for (int i = 0; i < size; i++) {
			pushBack(elements[i]);
		}
	}
	// Destructor
	~LinkedList() {
		clear();
	}
	// Return first index of element. -1 if do not contain 
	int indexOf(T element) {
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
	bool isEmpty() {
		return elementAmount == 0;
	}
	// Return true, if List contains Element. Type of Element must have overload "==" operator
	bool contains(T element) {
		return indexOf(element) != -1;
	};
	// Return amount of cointained elements
	int size() {
		return elementAmount;
	};
	// Add element in the end of array. Extend array if it necessary
	void pushBack(T element) {
		if (head == nullptr) {
			head = new ListNode<T>(element, nullptr);
			tail = head;
		}
		else {
			ListNode<T> newElem = new ListNode<T>(element, nullptr);
			tail->next = newElem;
			tail = tail->next;
		}
		++elementAmount;
	};
	// Add element at the index in List.
	void pushIndex(T element, int index) {
		if (0 > index || index > elementAmount) // Check index
			return;
		ListNode<T>* curr = head;
		if (index == 0) {
			ListNode<T> newElem = new ListNode<T>(element, head);
			head = newElem;
		} else if (index == elementAmount) {
			pushBack(element);
		}
		else {
			for (int i = 1; i < index; i++) {
				curr = curr->next;
			}
			ListNode<T> newElem = new ListNode<T>(element, curr->next);
			curr->next = element;
		}
		++elementAmount;
	};
	// Delete Element from List by index
	T removeIndex(int index) {
		if (index < 0 || index >= elementAmount)
			return 0;
		ListNode<T>* res = head->next;
		ListNode<T>* prev = head;
		for (int i = 1; i < index; i++) {
			res = res->next;
			prev = prev->next;
		}
		prev->next = res->next->next;
		res->next = nullptr;
		return res;
	}

	// Clear List
	void clear() {
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
};

