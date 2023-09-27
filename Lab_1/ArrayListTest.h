#pragma once
#include <iostream>
#include <string>
#include"ArrayList.h"
using namespace std;
class ArrayListTest
{
private:
	List<int>* arrayList1 ;
	List<string>* arrayList2;
public:
	ArrayListTest() {
		arrayList1 = new ArrayList<int>();
		arrayList2 = new ArrayList<string>();
	}
	void mainTest() {
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
	}
	bool isEmptyTest() {
		if (!arrayList1->isEmpty()) {
			cout << "isEmptyTest Failed 1" << endl;
			return false;
		}
		if (!arrayList2->isEmpty()) {
			cout << "isEmptyTest Failed 2" << endl;
			return false;
		}
		arrayList1->pushBack(0);
		arrayList2->pushBack("first string");
		if (arrayList1->isEmpty()) {
			cout << "isEmptyTest Failed 3" << endl;
			return false;
		}
		if (arrayList2->isEmpty()) {
			cout << "isEmptyTest Failed 4" << endl;
			return false;
		}
		cout << "isEmptyTest Passed" << endl;
		return true;
	}
	bool sizeTest() {
		ArrayList<int>* emptyArrayList = new ArrayList<int>();
		if (emptyArrayList->size() != 0) {
			cout << "sizeTest Failed 1" << endl;
			return false;
		}
		if (arrayList1->size() != 1) {
			cout << "sizeTest Failed 2" << endl;
			return false;
		}
		for (int i = 0; i < 41; i++) {
			emptyArrayList->pushBack(i);
		}
		if (emptyArrayList->size() != 41) {
			cout << "sizeTest Failed 3" << endl;
			return false;
		}
		cout << "sizeTest Passed" << endl;
		return true;
	}
	bool pushBackTest() {
		ArrayList<int>* emptyArrayList = new ArrayList<int>();
		emptyArrayList->pushBack(4);
		if (emptyArrayList->get(0) != 4) {
			cout << "pushBackTest Failed 1" << endl;
			return false;
		}
		arrayList1->pushBack(1);
		arrayList1->pushBack(2);
		if (arrayList1->get(2) != 2) {
			cout << "pushBackTest Failed 2" << endl;
			return false;
		}
		arrayList2->pushBack("second string");
		if (!arrayList2->get(1)._Equal("second string")) {
			cout << "pushBackTest Failed 3" << endl;
			return false;
		}
		cout << "pushBackTest Passed" << endl;
		return true;
	}
	bool pushIndexTest() {
		arrayList1->pushIndex(-1, 0);
		if (arrayList1->get(0) != -1 && arrayList1->get(1) != 0) {
			cout << "pushIndexTest Failed 1" << endl;
			return false;
		}
		arrayList1->pushIndex(99, 4);
		if (arrayList1->get(4) != 99) {
			cout << "pushIndexTest Failed 2" << endl;
			return false;
		}
		arrayList2->pushIndex("insert string",1);
		if (!arrayList2->get(1)._Equal("insert string") ||
			!arrayList2->get(2)._Equal("second string")) {
			cout << "pushBackTest Failed 3" << endl;
			return false;
		}
		cout << "pushIndexTest Passed" << endl;
		return true;
	}
	bool indexOfTest() {
		if (arrayList1->indexOf(313) != -1) {
			cout << "indexOfTest Failed 1" << endl;
			return false;
		}
		if (arrayList1->indexOf(-1) != 0) {
			cout << "indexOfTest Failed 2" << endl;
			return false;
		}
		if (arrayList1->indexOf(99) != 4) {
			cout << "indexOfTest Failed 3" << endl;
			return false;
		}
		if (arrayList2->indexOf("second string") != 2) {
			cout << "indexOfTest Failed 4" << endl;
			return false;
		}
		cout << "indexOfTest Passed" << endl;
		return true;
	}
	bool containsTest() {
		if (arrayList1->contains(3122)) {
			cout << "containsTest Failed 1" << endl;
			return false;
		}
		if (!arrayList1->contains(2)) {
			cout << "containsTest Failed 2" << endl;
			return false;
		}
		if (!arrayList1->contains(-1)) {
			cout << "containsTest Failed 3" << endl;
			return false;
		}
		if (arrayList2->contains("")) {
			cout << "containsTest Failed 4" << endl;
			return false;
		}
		if (!arrayList2->contains("insert string")) {
			cout << "containsTest Failed 5" << endl;
			return false;
		}
		cout << "containsTest Passed " << endl;
		return true;
	}
	bool addAllTest() {
		List<int> *ar = new ArrayList<int>();
		ar->pushBack(2);
		ar->pushBack(4);
		ar->pushBack(6);
		ar->pushBack(8);
		int size1 = arrayList1->size();
		ar->addAll(arrayList1);
		if (ar->size() != 4 + size1){
			cout << "addAllTest Failed 1" << endl;
			return false;
		}
		if (ar->get(4) != arrayList1->get(0)) {
			cout << "addAllTest Failed 2" << endl;
			return false;
		}
		if (ar->get(3 + size1) != arrayList1->get(size1-1)) {
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
		arrayList1->set(10, 0);
		if (arrayList1->get(0) != 10) {
			cout << "setTest Failed 1" << endl;
			return false;
		}
		arrayList1->set(13, 3);
		if (arrayList1->get(3) != 13) {
			cout << "setTest Failed 2" << endl;
			return false;
		}
		arrayList2->set("eee111", 2);
		if (!arrayList2->get(2)._Equal("eee111")) {
			cout << "setTest Failed 3" << endl;
			return false;
		}
		try {
			arrayList2->set("eee1", 211);
		}
		catch (out_of_range e) {
			cout << "setTest Failed 4" << endl;
			return false;
		}
		cout << "setTest Passed" << endl;
		return true;
	}
	bool getTest() {
		List<int>* ar = new ArrayList<int>();
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
		if (!arrayList2->get(2)._Equal("eee111")) {
			cout << "getTest Failed 3" << endl;
			return false;
		}
		cout << "getTest Passed" << endl;
		return true;
	}
	bool removeIndexTest() {
		List<int>* ar = new ArrayList<int>();
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
		if (!arrayList2->removeIndex(1)._Equal("insert string") ||
			!arrayList2->get(1)._Equal("eee111")) {
			cout << "removeIndexTest Failed 3" << endl;
			return false;
		}
		cout << "removeIndexTest Passed" << endl;
		return true;
	}
	bool removeElemTest() {
		List<int>* ar = new ArrayList<int>();
		ar->pushBack(2);
		ar->pushBack(4);
		ar->pushBack(6);
		ar->pushBack(8);
		List<string>* strar = new ArrayList<string>();
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
		List<int>* intClone = arrayList1->clone();
		List<string>* strClone = arrayList2->clone();
		if (intClone->size() != arrayList1->size()) {
			cout << "cloneTest Failed 1" << endl;
			return false;
		}
		if (strClone->size() != arrayList2->size()) {
			cout << "cloneTest Failed 2" << endl;
			return false;
		}
		for (int i = 0; i < arrayList1->size(); i++) {
			if (intClone->get(i) != arrayList1->get(i)) {
				cout << "cloneTest Failed 1" << endl;
				return false;
			}
		}
		for (int i = 0; i < arrayList2->size(); i++) {
			if (!strClone->get(i)._Equal(arrayList2->get(i))) {
				cout << "cloneTest Failed 2" << endl;
				return false;
			}
		}
		cout << "cloneTest Passed" << endl;
		return true;
	}
	bool clearTest() {
		ArrayList<int>* emptyArrayList = new ArrayList<int>();
		emptyArrayList->clear();
		arrayList1->clear();
		arrayList2->clear();
		if (arrayList1->size() != 0) {
			cout << "clearTest Failed 1" << endl;
			return false;
		}
		if (arrayList2->size() != 0) {
			cout << "clearTest Failed 2" << endl;
			return false;
		}
		if (emptyArrayList->size() != 0) {
			cout << "clearTest Failed 3" << endl;
			return false;
		}
		cout << "clearTest Passed" << endl;
		return true;
	}
};

