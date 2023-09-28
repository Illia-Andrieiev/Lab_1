#pragma once
#include <iostream>
#include <chrono>
#include"Graf.h"
#include "ArrayList.h"
using namespace std;
class GrafTest
{
private:
	List<int>* ar;
public:
	GrafTest() {
		ar = new ArrayList<int>();
		ar->pushBack(0);
		ar->pushBack(2);
		ar->pushBack(4);
		ar->pushBack(6);
		ar->pushBack(8);
	}
	void mainTest() {
		cout << "Testing Graf class:" << endl << endl;
		if (!addTest())
			return;
		if (!addVertexesTest())
			return;
		if (!addEdgesTest())
			return;
		if (!removeIndexTest())
			return;
		if (!removeElemTest())
			return;
		if (!nomerOfVertexTest())
			return;
		if (!getVertexTest())
			return;
		if (!removeEdgesTest())
			return;
		if (!containsTest())
			return;
		if (!containsEdge())
			return;
		if (!isConnectedVertexTest())
			return;
		findConnectionComponentTest();
		findOstTreeTest();
		microBenchmarking(100000);
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
	bool removeIndexTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		graf->add(-1);
		graf->add(2);
		graf->add(6);
		if (graf->removeIndex(0) != 4 || graf->getVertex(0) != -1) {
			cout << "removeIndexTest Failed 1" << endl;
			return false;
		}
		if (graf->removeIndex(1) != 2 || graf->getVertex(1) != 6) {
			cout << "removeIndexTest Failed 2" << endl;
			return false;
		}
		if (graf->removeIndex(1) != 6) {
			cout << "removeIndexTest Failed 3" << endl;
			return false;
		}
		if (graf->vertexAmount() != 1) {
			cout << "removeIndexTest Failed 4" << endl;
			return false;
		}
		try {
			graf->removeIndex(-12);
			graf->removeIndex(12);
		}
		catch (out_of_range e) {
			cout << "removeIndexTest Failed 5" << endl;
		}
		cout << "removeIndexTest Passed" << endl;
		return true;
		
	}
	bool removeElemTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		graf->add(-1);
		graf->add(2);
		graf->add(6);
		graf->removeElem(4);
		if (graf->getVertex(0) != -1) {
			cout << "removeElemTest Failed 1" << endl;
			return false;
		}
		graf->removeElem(2);
		if (graf->getVertex(1) != 6) {
			cout << "removeElemTest Failed 2" << endl;
			return false;
		}
		if (graf->vertexAmount() != 2) {
			cout << "removeIndexTest Failed 3" << endl;
			return false;
		}
		cout << "removeElemTest Passed" << endl;
		return true;

	}
	bool nomerOfVertexTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		graf->add(-1);
		graf->add(2);
		graf->add(6);
		if (graf->nomerOfVertex(4) != 0) {
			cout << "nomerOfVertexTest Failed 1" << endl;
			return false;
		}
		if (graf->nomerOfVertex(-1) != 1) {
			cout << "nomerOfVertexTest Failed 2" << endl;
			return false;
		}
		if (graf->nomerOfVertex(6) != 3) {
			cout << "nomerOfVertexTest Failed 3" << endl;
			return false;
		}
		if (graf->nomerOfVertex(63) != -1) {
			cout << "nomerOfVertexTest Failed 4" << endl;
			return false;
		}
		cout << "nomerOfVertexTest Passed" << endl;
		return true;
	}
	bool getVertexTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		graf->add(-1);
		graf->add(2);
		graf->add(6);
		if (graf->getVertex(0) != 4) {
			cout << "getVertexTest Failed 1" << endl;
			return false;
		}
		if (graf->getVertex(2) != 2) {
			cout << "getVertexTest Failed 2" << endl;
			return false;
		}
		if (graf->getVertex(3) != 6) {
			cout << "getVertexTest Failed 3" << endl;
			return false;
		}
		if (graf->getVertex(3) != 6) {
			cout << "getVertexTest Failed 3" << endl;
			return false;
		}
		int v1 = graf->getVertex(32);
		int v2 = graf->getVertex(-1);
		if (v1 != 0 || v2 != 0) {
			cout << "getVertexTest Failed 4" << endl;
			return false;
		}
		cout << "getVertexTest Passed" << endl;
		return true;
	}
	bool removeEdgesTest() {
		Graf<int>* graf = new Graf<int>();
		int arr[] = { -2,-10, 4};
		graf->addVertexes(arr, 3);
		int edge1[] = { 0,1 };
		int edges[] = {0,2,1,2 };
		graf->addEdges(edges, 4);
		graf->addEdges(edge1, 2);
		graf->removeEdges(edge1, 2);
		if (graf->containsEdge(edge1)) {
			cout << "removeEdgesTest Failed 1" << endl;
			return false;
		}
		graf->removeEdges(edges, 4);
		if (graf->containsEdge(edges)) {
			cout << "removeEdgesTest Failed 2" << endl;
			return false;
		}
		if (graf->containsEdge(&edges[2])) {
			cout << "removeEdgesTest Failed 3" << endl;
			return false;
		}
		cout << "removeEdgesTest Passed" << endl;
		return true;
	}
	bool containsTest() {
		Graf<int>* graf = new Graf<int>();
		graf->add(4);
		graf->add(-1);
		graf->add(2);
		graf->add(6);
		if (!graf->contains(4)) {
			cout << "containsTest Failed 1" << endl;
			return false;
		}
		if (!graf->contains(-1)) {
			cout << "containsTest Failed 2" << endl;
			return false;
		}
		if (!graf->contains(6)) {
			cout << "containsTest Failed 3" << endl;
			return false;
		}
		if (graf->contains(1)) {
			cout << "containsTest Failed 4" << endl;
			return false;
		}
		cout << "containsTest Passed" << endl;
		return true;
	}
	bool containsEdge() {
		Graf<int>* graf = new Graf<int>();
		int arr[] = { -2,-10, 4 };
		graf->addVertexes(arr, 3);
		int edge1[] = { 0,1 };
		int edge2[] = { 0,2 };
		int edge3[] = { 1,2 };
		int edge2rev[] = { 2,0 };
		graf->addEdges(edge2, 2);
		graf->addEdges(edge1, 2);
		if (!graf->containsEdge(edge1)) {
			cout << "containsEdgeTest Failed 1" << endl;
			return false;
		}
		if (!graf->containsEdge(edge2rev)) {
			cout << "containsEdgeTest Failed 2" << endl;
			return false;
		}
		if (graf->containsEdge(edge3)) {
			cout << "containsEdgeTest Failed 3" << endl;
			return false;
		}
		cout << "containsEdgeTest Passed" << endl;
		return true;
	}
	bool isConnectedVertexTest() {
		int edges[] = { 0,1,0,2,3,4};
		Graf<int>* graf = new Graf<int>(ar);
		graf->addEdges(edges, 6);
		if (!graf->isConnectedVertex(0, 1)) {
			cout << "isConnectedVertexTest Failed 1" << endl;
			return false;
		}
		if (!graf->isConnectedVertex(2, 1)) {
			cout << "isConnectedVertexTest Failed 2" << endl;
			return false;
		}
		if (!graf->isConnectedVertex(4, 3)) {
			cout << "isConnectedVertexTest Failed 3" << endl;
			return false;
		}
		if (graf->isConnectedVertex(4, 0)) {
			cout << "isConnectedVertexTest Failed 4" << endl;
			return false;
		}
		if (graf->isConnectedVertex(8, 6)) {
			cout << "isConnectedVertexTest Failed 5" << endl;
			return false;
		}
		cout << "isConnectedVertexTest Passed" << endl;
		return true;
	}
	void findConnectionComponentTest() {
		int edges1[] = { 0,1,0,2,3,4 };
		int edges2[] = { 0,1,0,2,0,3,0,4,1,2,1,3,1,4,2,3,2,4,3,4 };
		Graf<int>* emptyGraf = new Graf<int>();
		Graf<int>* grafWithoutEdges = new Graf<int>(ar);
		Graf<int>* graf1 = new Graf<int>(ar);
		graf1->addEdges(edges1, 6);
		Graf<int>* grafK5 = new Graf<int>(ar);
		grafK5->addEdges(edges2, 20);
		cout << endl << "findConnectionComponentTest processing:" << endl;
		//**************************************************************************
		List<Graf<int>*>* emptyGrafComponents = emptyGraf->findConnectionComponent();
		if (emptyGrafComponents != nullptr)
			cout << "emptyGrafComponents != nullptr. findConnectionComponentTest Failed." << endl;
		//**************************************************************************
		cout << "grafWithoutEdges:" << endl;
		grafWithoutEdges->print();
		cout << endl << "grafWithoutEdges components:" << endl;
		List<Graf<int>*>* grafWithoutEdgesComponents = grafWithoutEdges->findConnectionComponent();
		for (int i = 0; i < grafWithoutEdgesComponents->size(); i++) {
			grafWithoutEdgesComponents->get(i)->print();
			//cout << comp->get(i)->vertexAmount()<< endl;
		}
		//**************************************************************************
		cout << "graf1:" << endl;
		graf1->print();
		cout << endl << "graf1 components." << endl;
		List<Graf<int>*>* graf1Components = graf1->findConnectionComponent();
		for (int i = 0; i < graf1Components->size(); i++) {
			graf1Components->get(i)->print();
			//cout << comp->get(i)->vertexAmount()<< endl;
		}
		//**************************************************************************
		cout << "grafK5:" << endl;
		grafK5->print();
		cout << endl << "grafK5 components." << endl;
		List<Graf<int>*>* grafK5Components = grafK5->findConnectionComponent();
		for (int i = 0; i < grafK5Components->size(); i++) {
			grafK5Components->get(i)->print();
			//cout << comp->get(i)->vertexAmount()<< endl;
		}
	}
	void findOstTreeTest() {
		int edges1[] = { 0,1,0,2,3,4 };
		int edges2[] = { 0,1,0,2,0,3,2,4,0,4,1,2,1,3,1,4,2,3,3,4 };
		Graf<int>* emptyGraf = new Graf<int>();
		Graf<int>* grafWithoutEdges = new Graf<int>(ar);
		Graf<int>* graf1 = new Graf<int>(ar);
		graf1->addEdges(edges1, 6);
		Graf<int>* grafK5 = new Graf<int>(ar);
		grafK5->addEdges(edges2, 20);
		cout << endl << "findOstTreeTest processing:" << endl;
		//**************************************************************************
		Graf<int>* emptyGrafTree = emptyGraf->findOstTree();
		if (emptyGrafTree != nullptr)
			cout << "emptyGrafTree != nullptr. findOstTreeTest Failed." << endl;
		//**************************************************************************
		cout << "grafWithoutEdges:" << endl;
		grafWithoutEdges->print();
		cout << endl << "grafWithoutEdges Ost Tree:" << endl;
		Graf<int>* grafWithoutEdgesTree = grafWithoutEdges->findOstTree();
		grafWithoutEdgesTree->print();
		//**************************************************************************
		cout << "graf1:" << endl;
		graf1->print();
		cout << endl << "graf1 Ost Tree:" << endl;
		Graf<int>* graf1Tree = graf1->findOstTree();
		graf1Tree->print();
		//**************************************************************************
		cout << "grafK5:" << endl;
		grafK5->print();
		cout << endl << "grafK5 Ost Tree:" << endl;
		Graf<int>* grafK5Tree = grafK5->findOstTree();
		grafK5Tree->print();
	}
	void microBenchmarking(int n) {
		int edges2[] = { 0,1,0,2,0,3,2,4,0,4,1,2,1,3,1,4,2,3,3,4 };
		int edges1[] = { 0,1,0,2,3,4 };;
		uint64_t startSec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		for (int i = 0; i < n; i++) {
			Graf<int>* grafK5 = new Graf<int>(ar);
			Graf<int>* graf1 = new Graf<int>(ar);
			grafK5->addEdges(edges2, 20);
			graf1->addEdges(edges1, 6);
			List<Graf<int>*>* ostForestK5 = grafK5->findOstForest();
			List<Graf<int>*>* ostForest1 = graf1->findOstForest();
		}
		uint64_t endSec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		cout << (double_t)endSec - (double_t)startSec << " seconds for " << n << " cycles" << endl;
	}
};