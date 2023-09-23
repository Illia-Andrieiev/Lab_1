#include<iostream>
#include "ArrayList.h"
#include "LinkedList.h"
using namespace std;

int main() {
	List<int> *ar = new LinkedList<int>();
	ar->pushBack(2);
	ar->pushBack(4);
	ar->pushBack(6);
	ar->pushBack(8);
	ar->print();
	cout  << endl << ar->size() << endl;
	ar->pushIndex(3, 3);
	ar->print();
	cout  << endl << ar->size() << endl;
	int res = ar->removeIndex(2);
	cout << res << endl;
	ar->print();
	cout << endl << ar->size() << endl;
	system("pause");
	return 0;
}