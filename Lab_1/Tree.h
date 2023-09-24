#pragma once
#include"TreeNode.h"
#include "BaseTree.h"
#include"List.h"
template<typename T>
class Tree :
    public BaseTree<T>
{
private:
    int n;
    TreeNode<T>* root;
    int elementAmount;
public:
    Tree(int n);
    Tree(List<T>* list, int n);
    void add(T element);
    void addAll(List<T>* list);
    void removeElem(T element);
    bool contains(T element);
    void print();
};

