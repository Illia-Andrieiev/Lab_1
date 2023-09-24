#pragma once
#include "Graf.h"
#include "ArrayList.h"
//******************************************************************
/*
							PRIVATE METHODS
*/
//******************************************************************
// Create matrix NxN with list
template<typename T>
bool** Graf<T>::createMatrix(int n, int* edges, int sizeE) {
	bool** res = new bool* [n];
	for (int i = 0; i < n; i++)
		res[i] = new bool[n];
	if (edges != nullptr) {
	
	}
	return res;
} 
// Available edge nomer
template<typename T>
bool Graf<T>::isCorrectEdgeNomer(int* edges, int size) {
	for (int i = 0; i < size; i++) {
		if (edges >= vertexes->size())
			return false;
	}
	return true;
}
// Delete all edges with for vertex by nomer
template<typename T>
void Graf<T>::deleteAllVertexesEdges(int nomer) {
	int curr = 0;
	while (curr < edges->size()) { // Delete edges from graf
		if (edges->get(curr) == nomer || edges->get(curr + 1) == nomer) {
			edges->removeIndex(curr);
			edges->removeIndex(curr);
		}
		else
			curr += 2;
	}
}
// Delete one edge from graf
template<typename T>
void  Graf<T>::deleteOneEdge(int* edge) {
	int curr = 0;
	while (curr < edges->size()) {
		if ((edges->get(curr) == edge[0] && edges->get(curr + 1) == edge[1]) ||
			(edges->get(curr + 1) == edge[0] && edges->get(curr) == edge[1])) {
			edges->removeIndex(curr);
			edges->removeIndex(curr);
		}else
			curr += 2;
	}
};
//******************************************************************
/*
							PUBLIC METHODS
*/
//******************************************************************
// Constructors
template<typename T>
Graf<T>::Graf() {
	vertexes = new ArrayList<T>();
	edges = new ArrayList<int>();
}
template<typename T>
Graf<T>::Graf(T* vertex, int size) {
	vertexes = new ArrayList<T>(vertex,size);
	edges = new ArrayList<int>();
}
template<typename T>
Graf<T>::Graf(List<T>* vertex) {
	vertexes = new ArrayList<T>();
	vertexes->addAll(vertex);
	edges = new ArrayList<int>();
};
template<typename T>
Graf<T>::Graf(T* vertex, int sizeV, int* edges, int sizeE) {
	if (sizeE % 2 != 0) // One edge must given by two vertex nomers 
		--sizeE;
	vertexes = new ArrayList<T>(vertex, sizeV);
	this.edges = new ArrayList<int>(edges,sizeE);
}
template<typename T>
Graf<T>::Graf(List<T>* vertex, int* edges, int sizeE) {
	if (sizeE % 2 != 0) // One edge must given by two vertex nomers 
		--sizeE;
	vertexes = new ArrayList<T>();
	vertexes->addAll(vertex);
	this.edges = new ArrayList<int>(edges, sizeE);
}
// Destructor
template<typename T>
Graf<T>::~Graf() {
	delete vertexes;
	delete edges;
};
// Add one Vertex
template<typename T>
void Graf<T>::add(T element) {
	vertexes->pushBack(element);
}
// Add List of Vertexes
template<typename T>
void Graf<T>::addVertexes(List<T>* list) {
	vertexes->addAll(list);
}
// Add array of Vertexes
template<typename T>
void Graf<T>::addVertexes(T* arr, int size) {
	vertexes->addAll(arr, size);
}
// Add array of Edges
template<typename T>
void Graf<T>::addEdges(int* arr, int size) {
	if (isCorrectEdgeNomer(arr, size))
		edges->addAll(arr, size);
	else
		std::cout << " edge nomer more then maximum vertex nomer";
}
// Remove vertex by index. Delete all edges with it. 0 if index out of borders.
template<typename T>
T Graf<T>::removeIndex(int nomer) {
	if (nomer >= vertexes->size() || nomer < 0)
		return 0;
	deleteAllVertexesEdges(nomer);
	return vertexes->removeIndex(nomer); // Return removed element
};
// Remove vertex. Delete all edges with it.
template<typename T>
void Graf<T>::removeElem(T element) {
	removeIndex(nomerOfVertex(element));
};
// Return nomer of vertex
template<typename T>
int  Graf<T>::nomerOfVertex(T element) {
	return vertexes->indexOf(element);
}
// Remove some edges
template<typename T>
void Graf<T>::removeEdges(int* edges, int size) {
	if (size % 2 != 0 || size < 2 || size > vertexes->size())
		return;
	for (int i = 0; i < size; i += 2)
		deleteOneEdge(&edges[i]);
}
// Return vertex by index. 0 if index out of borders
template<typename T>
T Graf<T>::getVertex(int nomer){
	return vertexes->get(nomer);
}
// Print Graf
template<typename T>
void Graf<T>::print() {
	std::cout << "vertexes:" << std::endl;
	vertexes->print();
	std::cout << std::endl << "edges:" << std::endl;
	edges->print();
}
// Is contain graf element
template<typename T>
bool Graf<T>::contains(T element) {
	return vertexes->contains(element);
}
// Is contain graf edge
template<typename T>
bool Graf<T>::containsEdge(int* edge){
	int curr = 0;
	try {
		while (curr < edges->size()) { // Delete edges from graf
			if ((edges->get(curr) == edge[0] && edges->get(curr + 1) == edge[1]) ||
				(edges->get(curr) == edge[1] && edges->get(curr + 1) == edge[0]))
				return true;
			else
				curr += 2;
		}
	}catch (std::out_of_range e) {
		std::cout << "Array of edge vertexes must have 2 int vales!";
	}
	return false;
}