#include "TreeNode.h"
template<typename T>
TreeNode<T>::TreeNode(T data) {
	this->data = data;
	next = new ArrayList<TreeNode<T>*>();
}