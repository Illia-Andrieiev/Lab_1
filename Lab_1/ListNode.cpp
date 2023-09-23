#include "ListNode.h"
template<typename T>
ListNode<T>::ListNode(T data, ListNode<T>* next) {
	this->data = data;
	this->next = next;
}