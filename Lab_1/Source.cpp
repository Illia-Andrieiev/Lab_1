#include<iostream>
#include "ArrayList.h"
using namespace std;

int main() {
	List<int> *ar = new ArrayList<int>();
	ar->pushBack(2);
	ar->pushBack(4);
	ar->pushBack(6);
	ar->pushBack(8);
	ar->print();
	cout << ar->size() << endl;
	ar->pushIndex(3, 4);
	int res = ar->removeIndex(2);
	cout << ar->size() << endl;
	ar->print();
	system("pause");
	return 0;
}