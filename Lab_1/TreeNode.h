#pragma once
#include "ArrayList.cpp"
template<typename T>
class TreeNode
{
public:
	T data;
	ArrayList<TreeNode<T>*> next;
	TreeNode(T data);
};

