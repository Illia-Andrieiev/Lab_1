#pragma once
#include <iostream>
#include <chrono>
#include"Graf.h"
#include "ArrayList.h"
using namespace std;
class GrafTest
{
public:
	GrafTest() {
	}
	void mainTest() {
		cout << "Testing Graf class:" << endl << endl;
		if (!addTest())
			return;
		if (!addVertexesTest())
			return;
		if (addEdgesTest())
			return;
		cout << endl << "Graf class testing complete successfuly:" << endl << endl;
	}
	bool addTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		if (graf->getVertex(0) != 4 || graf->vertexAmount() != 1) {
			cout << "addTest Failed 1" << endl;
			return false;
		}
		graf->add(1);
		graf->add(2);
		if (graf->getVertex(2) != 2 || graf->vertexAmount() != 3) {
			cout << "addTest Failed 2" << endl;
			return false;
		}
		cout << "addTest Passed" << endl;
		return true;
	}
	bool addVertexesTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		int arr[] = {-2,-10};
		ArrayList<int>* list = new ArrayList<int>();
		list->pushBack(7);
		list->pushBack(-2);
		graf->addVertexes(list);
		if (graf->getVertex(1) != 7 || graf->getVertex(2) != -2
			|| graf->vertexAmount() != 3) {
			cout << "addAllTest Failed 1" << endl;
			return false;
		}
		graf->addVertexes(arr, 2);
		if (graf->getVertex(3) != -2 || graf->getVertex(4) != -10
			|| graf->vertexAmount() != 5) {
			cout << "addAllTest Failed 2" << endl;
			return false;
		}
		cout << "addAllTest Passed" << endl;
		return true;
	}
	bool addEdgesTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		int arr[] = { -2,-10 };
		graf->addVertexes(arr, 2);
		int edge1[] = { 0,1 };
		int edge2[] = { 4,1 };
		int edges[] = { 0,2,1,2 };
		graf->addEdges(edge1, 2);
		if (!graf->containsEdge(edge1)) {
			cout << "addEdgesTest Failed 1" << endl;
			return false;
		}
		graf->addEdges(edge2, 2);
		if (graf->containsEdge(edge2)) {
			cout << "addEdgesTest Failed 2" << endl;
			return false;
		}
		graf->addEdges(edges, 4);
		if (!graf->containsEdge(edges) || !graf->containsEdge(&edges[2])) {
			cout << "addEdgesTest Failed 3" << endl;
			return false;
		}
		cout << "addEdgesTest Passed" << endl;
		return true;
	}
};

