#include "TreeNode.h"
template<typename T>
TreeNode<T>::TreeNode(T data, ArrayList<TreeNode<T>*> next) {
	this->data = data;
	this->next = next;
}