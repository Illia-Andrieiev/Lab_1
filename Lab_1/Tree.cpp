#include "Tree.h"
//******************************************************************
/*
							PUBLIC METHODS
*/
//******************************************************************
// Constructors
template<typename T>
Tree<T>::Tree() {
	root = nullptr;
	elementAmount = 0;
};
template<typename T>
Tree<T>::Tree(List<T>* list) {
	root = nullptr;
	elementAmount = 0;
	addAll(list);
};
template<typename T>
void Tree<T>::add(T element);
template<typename T>
void Tree<T>::addAll(List<T>* list);
template<typename T>
void Tree<T>::removeElem(T element);
template<typename T>
bool Tree<T>::contains(T element);
template<typename T>
void Tree<T>::print();