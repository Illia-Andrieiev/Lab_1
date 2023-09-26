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
// Find all connected edges for vertex 
template<typename T>
List<int>* Graf<T>::findAllVertexesEdges(int nomer) {
	List<int>* res = new ArrayList<int>();
	int curr = 0;
	while (curr < edges->size()) { 
		if (edges->get(curr) == nomer || edges->get(curr + 1) == nomer) {
			res->pushBack(edges->get(curr));
			res->pushBack(edges->get(curr+1));
		}
		curr += 2;
	}
	return res;
}
// Check if List contain edge
template<typename T>
bool Graf<T>::isContainEdge(List<int>* edges, int* edge){
	int curr = 0;
	while (curr < edges->size()) {
		if ((edges->get(curr) == edge[0] && edges->get(curr + 1) == edge[1]) ||
			(edges->get(curr) == edge[1] && edges->get(curr + 1) == edge[0]))
			return true;
		else
			curr += 2;
	}
	return false;
}
// Add in first list unique edges from second list
template<typename T>
void Graf<T>::AddUniqueEdges(List<int>* old, List<int>* newEdges) {
	for (int i = 0; i < newEdges->size(); i += 2) {
		int* edge = new int[2];
		edge[0] = newEdges->get(i);
		edge[1] = newEdges->get(i + 1);
		if (!isContainEdge(old, edge)) {
			old->addAll(edge, 2);
		}
		delete[] edge;
	}
}
// Available edge nomer
template<typename T>
bool Graf<T>::isCorrectEdgeNomer(int* edges, int size) {
	for (int i = 0; i < size; i++) {
		if (edges[i] >= vertexes->size())
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
		for (int i = 0; i < size; i += 2) {
			if (!containsEdge(&arr[i]))
				edges->addAll(&arr[i], 2);
		}
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
		while (curr < edges->size()) {
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
// Find all connection components for graf
template<typename T>
List<Graf<T>*>* Graf<T>::findConnectionComponent() {
	List<Graf<T>*>* ConnectionComponents = new ArrayList<Graf<T>*>();
	bool* checked = new bool[vertexes->size()];
	for (int i = 0; i < vertexes->size(); i++) {
		checked[i] = false;
	}
	for (int i = 0; i < vertexes->size(); i++) { // Checking all vertex
		if (!checked[i]) { // If not connected with previous, find new component
			ConnectionComponents->pushBack(findConnectionComponentForVertex(i, checked));
		}
	}
	delete[] checked;
	return ConnectionComponents;
}
// Find one connection component, that include "nomer" vertex
template<typename T>
Graf<T>* Graf<T>::findConnectionComponentForVertex(int nomer, bool* checked) {
	Graf<T>* connectionComponent = new Graf<T>(); // res
	List<int>* queue = new ArrayList<int>(); // queue for all connected vertexes
	queue->pushBack(nomer);
	while (!queue->isEmpty()) {
		connectionComponent->add(this->getVertex(queue->get(0))); // Add vertex to component
		checked[queue->get(0)] = true; // mark as vievd
		List<int>* vertexesEdges = findAllVertexesEdges(queue->get(0)); // Find all connected edges
		AddUniqueEdges(connectionComponent->edges, vertexesEdges); // Add unique edges to component
		for (int i = 0; i < vertexesEdges->size(); i++) { // Check edges for new connected vertexes and add to queue
			if (!checked[vertexesEdges->get(i)]) {
				checked[queue->get(0)] = true;

				queue->pushBack(vertexesEdges->get(i));
			}
		}
		queue->removeIndex(0);
	}
	return connectionComponent;
};