#pragma once
#include "TreeNode.h"
template<typename T>
TreeNode<T>::TreeNode(T data) {
	this->data = data;
	this->next = new ArrayList<TreeNode<T>*>();
}