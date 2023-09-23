#include "Tree.h"
#include"LinkedList.h"
//******************************************************************
/*
							PUBLIC METHODS
*/
//******************************************************************
// Constructors
template<typename T>
Tree<T>::Tree(int n) {
	root = nullptr;
	elementAmount = 0;
	this->n = n;
};
template<typename T>
Tree<T>::Tree(List<T>* list, int n) {
	root = nullptr;
	elementAmount = 0;
	addAll(list);
	this->n = n;
};
template<typename T>
// Add element to Tree by tier
void Tree<T>::add(T element) {
	if (root == nullptr) {
		root = new TreeNode<T>(element);
		++elementAmount;
		return;
	}
	LinkedList<TreeNode<T>*> queue = new LinkedList<TreeNode<T>*>();
	queue->pushBack(root);
	while (true) {
		if (queue->getHead()->next->size() =< n) {
			queue->getHead()->next->pushBack(new TreeNode<T>(element));
			++elementAmount;
			break;
		}
		queue->addAll(queue->getHead()->next);
		queue->remove(0);
	}
	queue->clear(); //???????????????????????? Maybe delete tree????????????????????
};
// Add all list elements to Tree by tier
template<typename T>
void Tree<T>::addAll(List<T>* list) {
	for (int i = 0; i < other->size(); i++) {
		add(list->get(i));
	}
};
// Remove element
template<typename T>
void Tree<T>::removeElem(T element) {
	if (root == nullptr)
		return;
	LinkedList<TreeNode<T>*> queue = new LinkedList<TreeNode<T>*>();
	queue->pushBack(root);
	while (!queue->isEmpty) {
		if (queue->getHead()->data == element) {
			TreeNode<T>* forDelete = queue->getHead();
			TreeNode<T>* temp = forDelete;
			while (temp->next->size() != 0) {
				temp = temp->next->get(0);
			}
			forDelete->data = temp->data;
			delete temp;
			break;
		}
		queue->addAll(queue->getHead()->next);
		queue->remove(0);
	}
	queue->clear(); //???????????????????????? Maybe delete tree????????????????????
};
template<typename T>
// Is contatains tree element
bool Tree<T>::contains(T element) {
	if (root == nullptr)
		return false;
	LinkedList<TreeNode<T>*> queue = new LinkedList<TreeNode<T>*>();
	queue->pushBack(root);
	while (!queue->isEmpty) {
		if (queue->getHead()->data == element) {
			return true;
		}
		queue->addAll(queue->getHead()->next);
		queue->remove(0);
	}
	queue->clear(); //???????????????????????? Maybe delete tree????????????????????
};
// Print tree by tier
template<typename T>
void Tree<T>::print() {
	if (root == nullptr)
		return;
	LinkedList<TreeNode<T>*> queue = new LinkedList<TreeNode<T>*>();
	queue->pushBack(root);
	while (!queue->isEmpty) {
		std::cout << queue->getHead()->data << " " << std::endl;
		queue->addAll(queue->getHead()->next);
		queue->remove(0);
	}
	queue->clear();//???????????????????????? Maybe delete tree????????????????????
};