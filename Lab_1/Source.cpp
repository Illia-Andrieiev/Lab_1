#include<iostream>
#include "LinkedList.cpp"
#include "Graf.cpp"

using namespace std;
int main() {
	List<int> *ar = new ArrayList<int>();
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
	List<int>* copy = new ArrayList<int>();
	copy->addAll(ar);
	copy->print();
	Graf<int>* graf = new Graf<int>(ar);
	graf->add(7);
	cout << endl << graf->getVertex(4) << endl;
	system("pause");
	return 0;
}