#pragma once
#include"TreeNode.h"
#include "BaseTree.h"
template<typename T>
class Tree :
    public BaseTree<T>
{
private:
    TreeNode<T>* root;
    int elementAmount;
public:
    Tree();
    Tree(List<T>* list);
    void add(T element);
    void addAll(List<T>* list);
    void removeElem(T element);
    bool contains(T element);
    void print();
};

