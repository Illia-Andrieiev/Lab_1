#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include"LinkedList.h"
using namespace std;
class LinkedListTest
{
private:
	List<int>* LinkedList1;
	List<string>* LinkedList2;
public:
	LinkedListTest() {
		LinkedList1 = new LinkedList<int>();
		LinkedList2 = new LinkedList<string>();
	}
	void mainTest() {
		cout << "Testing LinkedList class:" << endl << endl;
		if (!isEmptyTest())
			return;
		if (!sizeTest())
			return;
		if (!pushBackTest())
			return;
		if (!pushIndexTest())
			return;
		if (!indexOfTest())
			return;
		if (!containsTest())
			return;
		if (!addAllTest())
			return;
		if (!setTest())
			return;
		if (!getTest())
			return;
		if (!removeIndexTest())
			return;
		if (!removeElemTest())
			return;
		if (!cloneTest())
			return;
		if (!clearTest())
			return;
		microBenchmarking(10);
		cout << endl <<"LinkedList class testing complete successfuly:" << endl << endl;
	}
	bool isEmptyTest() {
		if (!LinkedList1->isEmpty()) {
			cout << "isEmptyTest Failed 1" << endl;
			return false;
		}
		if (!LinkedList2->isEmpty()) {
			cout << "isEmptyTest Failed 2" << endl;
			return false;
		}
		LinkedList1->pushBack(0);
		LinkedList2->pushBack("first string");
		if (LinkedList1->isEmpty()) {
			cout << "isEmptyTest Failed 3" << endl;
			return false;
		}
		if (LinkedList2->isEmpty()) {
			cout << "isEmptyTest Failed 4" << endl;
			return false;
		}
		cout << "isEmptyTest Passed" << endl;
		return true;
	}
	bool sizeTest() {
		LinkedList<int>* emptyLinkedList = new LinkedList<int>();
		if (emptyLinkedList->size() != 0) {
			cout << "sizeTest Failed 1" << endl;
			return false;
		}
		if (LinkedList1->size() != 1) {
			cout << "sizeTest Failed 2" << endl;
			return false;
		}
		for (int i = 0; i < 41; i++) {
			emptyLinkedList->pushBack(i);
		}
		if (emptyLinkedList->size() != 41) {
			cout << "sizeTest Failed 3" << endl;
			return false;
		}
		cout << "sizeTest Passed" << endl;
		return true;
	}
	bool pushBackTest() {
		LinkedList<int>* emptyLinkedList = new LinkedList<int>();
		emptyLinkedList->pushBack(4);
		if (emptyLinkedList->get(0) != 4) {
			cout << "pushBackTest Failed 1" << endl;
			return false;
		}
		LinkedList1->pushBack(1);
		LinkedList1->pushBack(2);
		if (LinkedList1->get(2) != 2) {
			cout << "pushBackTest Failed 2" << endl;
			return false;
		}
		LinkedList2->pushBack("second string");
		if (!LinkedList2->get(1)._Equal("second string")) {
			cout << "pushBackTest Failed 3" << endl;
			return false;
		}
		cout << "pushBackTest Passed" << endl;
		return true;
	}
	bool pushIndexTest() {
		LinkedList1->pushIndex(-1, 0);
		if (LinkedList1->get(0) != -1 && LinkedList1->get(1) != 0) {
			cout << "pushIndexTest Failed 1" << endl;
			return false;
		}
		LinkedList1->pushIndex(99, 4);
		if (LinkedList1->get(4) != 99) {
			cout << "pushIndexTest Failed 2" << endl;
			return false;
		}
		LinkedList2->pushIndex("insert string", 1);
		if (!LinkedList2->get(1)._Equal("insert string") ||
			!LinkedList2->get(2)._Equal("second string")) {
			cout << "pushBackTest Failed 3" << endl;
			return false;
		}
		cout << "pushIndexTest Passed" << endl;
		return true;
	}
	bool indexOfTest() {
		if (LinkedList1->indexOf(313) != -1) {
			cout << "indexOfTest Failed 1" << endl;
			return false;
		}
		if (LinkedList1->indexOf(-1) != 0) {
			cout << "indexOfTest Failed 2" << endl;
			return false;
		}
		if (LinkedList1->indexOf(99) != 4) {
			cout << "indexOfTest Failed 3" << endl;
			return false;
		}
		if (LinkedList2->indexOf("second string") != 2) {
			cout << "indexOfTest Failed 4" << endl;
			return false;
		}
		cout << "indexOfTest Passed" << endl;
		return true;
	}
	bool containsTest() {
		if (LinkedList1->contains(3122)) {
			cout << "containsTest Failed 1" << endl;
			return false;
		}
		if (!LinkedList1->contains(2)) {
			cout << "containsTest Failed 2" << endl;
			return false;
		}
		if (!LinkedList1->contains(-1)) {
			cout << "containsTest Failed 3" << endl;
			return false;
		}
		if (LinkedList2->contains("")) {
			cout << "containsTest Failed 4" << endl;
			return false;
		}
		if (!LinkedList2->contains("insert string")) {
			cout << "containsTest Failed 5" << endl;
			return false;
		}
		cout << "containsTest Passed " << endl;
		return true;
	}
	bool addAllTest() {
		List<int>* ar = new LinkedList<int>();
		ar->pushBack(2);
		ar->pushBack(4);
		ar->pushBack(6);
		ar->pushBack(8);
		int size1 = LinkedList1->size();
		ar->addAll(LinkedList1);
		if (ar->size() != 4 + size1) {
			cout << "addAllTest Failed 1" << endl;
			return false;
		}
		if (ar->get(4) != LinkedList1->get(0)) {
			cout << "addAllTest Failed 2" << endl;
			return false;
		}
		if (ar->get(3 + size1) != LinkedList1->get(size1 - 1)) {
			cout << "addAllTest Failed 3" << endl;
			return false;
		}
		int toAdd[] = { 66,22,-1223 };
		ar->addAll(toAdd, 3);
		if (ar->get(4 + size1) != 66) {
			cout << "addAllTest Failed 4" << endl;
			return false;
		}
		if (ar->get(6 + size1) != -1223) {
			cout << "addAllTest Failed 5" << endl;
			return false;
		}
		cout << "addAllTest Passed " << endl;
		return true;
	}
	bool setTest() {
		LinkedList1->set(10, 0);
		if (LinkedList1->get(0) != 10) {
			cout << "setTest Failed 1" << endl;
			return false;
		}
		LinkedList1->set(13, 3);
		if (LinkedList1->get(3) != 13) {
			cout << "setTest Failed 2" << endl;
			return false;
		}
		LinkedList2->set("eee111", 2);
		if (!LinkedList2->get(2)._Equal("eee111")) {
			cout << "setTest Failed 3" << endl;
			return false;
		}
		try {
			LinkedList2->set("eee1", 211);
		}
		catch (out_of_range e) {
			cout << "setTest Failed 4" << endl;
			return false;
		}
		cout << "setTest Passed" << endl;
		return true;
	}
	bool getTest() {
		List<int>* ar = new LinkedList<int>();
		ar->pushBack(2);
		ar->pushBack(4);
		ar->pushBack(6);
		ar->pushBack(8);
		if (ar->get(0) != 2) {
			cout << "getTest Failed 1" << endl;
			return false;
		}
		if (ar->get(3) != 8) {
			cout << "getTest Failed 2" << endl;
			return false;
		}
		if (!LinkedList2->get(2)._Equal("eee111")) {
			cout << "getTest Failed 3" << endl;
			return false;
		}
		cout << "getTest Passed" << endl;
		return true;
	}
	bool removeIndexTest() {
		List<int>* ar = new LinkedList<int>();
		ar->pushBack(2);
		ar->pushBack(4);
		ar->pushBack(6);
		ar->pushBack(8);
		if (ar->removeIndex(2) != 6 && ar->get(2) != 8) {
			cout << "removeIndexTest Failed 1" << endl;
			return false;
		}
		if (ar->removeIndex(0) != 2 && ar->get(0) != 4) {
			cout << "removeIndexTest Failed 2" << endl;
			return false;
		}
		if (!LinkedList2->removeIndex(1)._Equal("insert string") ||
			!LinkedList2->get(1)._Equal("eee111")) {
			cout << "removeIndexTest Failed 3" << endl;
			return false;
		}
		cout << "removeIndexTest Passed" << endl;
		return true;
	}
	bool removeElemTest() {
		List<int>* ar = new LinkedList<int>();
		ar->pushBack(2);
		ar->pushBack(4);
		ar->pushBack(6);
		ar->pushBack(8);
		List<string>* strar = new LinkedList<string>();
		strar->pushBack("ffff");
		strar->pushBack("insert string");
		strar->pushBack("eee111");
		strar->pushBack("fvasxsac");

		if (ar->removeElem(2) != 2 && ar->get(0) != 4) {
			cout << "removeElemTest Failed 1" << endl;
			return false;
		}
		if (ar->removeElem(8) != 8 && ar->get(2) != 6) {
			cout << "removeElemTest Failed 2" << endl;
			return false;
		}
		if (!strar->removeElem("insert string")._Equal("insert string") ||
			!strar->get(1)._Equal("eee111")) {
			cout << "removeElemTest Failed 3" << endl;
			return false;
		}
		cout << "removeElemTest Passed" << endl;
		return true;
	}
	bool cloneTest() {
		List<int>* intClone = LinkedList1->clone();
		List<string>* strClone = LinkedList2->clone();
		if (intClone->size() != LinkedList1->size()) {
			cout << "cloneTest Failed 1" << endl;
			return false;
		}
		if (strClone->size() != LinkedList2->size()) {
			cout << "cloneTest Failed 2" << endl;
			return false;
		}
		for (int i = 0; i < LinkedList1->size(); i++) {
			if (intClone->get(i) != LinkedList1->get(i)) {
				cout << "cloneTest Failed 1" << endl;
				return false;
			}
		}
		for (int i = 0; i < LinkedList2->size(); i++) {
			if (!strClone->get(i)._Equal(LinkedList2->get(i))) {
				cout << "cloneTest Failed 2" << endl;
				return false;
			}
		}
		cout << "cloneTest Passed" << endl;
		return true;
	}
	bool clearTest() {
		LinkedList<int>* emptyLinkedList = new LinkedList<int>();
		emptyLinkedList->clear();
		LinkedList1->clear();
		LinkedList2->clear();
		if (LinkedList1->size() != 0) {
			cout << "clearTest Failed 1" << endl;
			return false;
		}
		if (LinkedList2->size() != 0) {
			cout << "clearTest Failed 2" << endl;
			return false;
		}
		if (emptyLinkedList->size() != 0) {
			cout << "clearTest Failed 3" << endl;
			return false;
		}
		cout << "clearTest Passed" << endl;
		return true;
	}
	void microBenchmarking(int n) {
		uint64_t startSec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		for (int i = 0; i < n; i++) {
			LinkedList<int>* emptyArrayList = new LinkedList<int>();
			for (int i = 0; i < 20000; i++) {
				emptyArrayList->pushBack(i);
			}
			emptyArrayList->clear();
		}
		uint64_t endSec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		cout << (double_t)endSec - (double_t)startSec << " seconds for " << n << " cycles" << endl;
	}
};