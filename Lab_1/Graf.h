#pragma once
#include "BaseGraf.h"
#include"List.h"
/*
	GRAF REPRESENTED BY ADJACENCY VECTOR
*/
template<typename T>
class Graf : public BaseGraf<T>
{
private:
	List<T>* vertexes;
	List<int>* edges;// edges, that stored as pairs of vertex nomers
	bool** createMatrix(int n, int* edges, int sizeE);
	bool isCorrectEdgeNomer(int* edges, int size);
	void deleteAllVertexesEdges(int nomer);
	void deleteOneEdge(int* edge);
	bool isContainEdge(List<int>* edges, int* edge);
	void AddUniqueEdges(List<int>* old, List<int>* newEdges);
	List<int>* findAllVertexesEdges(int nomer);
	Graf<T>* findConnectionComponentForVertex(int nomer, bool* checked);
public:
	Graf();
	Graf(T* vertex, int size);
	Graf(List<T>* vertex);
	Graf(T* vertex,int sizeV, int* edges, int sizeE);
	Graf(List<T>* vertex, int* edges, int sizeE);
	~Graf();
	void add(T element);
	void addVertexes(List<T>* element);
	void addVertexes(T* element, int size);
	void addEdges(int* element, int size);
	T removeIndex(int nomer);
	void removeElem(T element);
	int nomerOfVertex(T element);
	T getVertex(int nomer);
	void removeEdges(int* edges, int size);
	bool contains(T element);
	bool containsEdge(int* element);
	void print();
	List<Graf<T>*>* findConnectionComponent();
};

