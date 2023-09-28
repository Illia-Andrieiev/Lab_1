#include "Graf.cpp"
#include "ArrayList.cpp"
#include "LinkedList.cpp"
#include "ArrayListTest.h"
#include "LinkedListTest.h"
#include "GrafTest.h"
using namespace std;
int main() {
	ArrayListTest* arrayListTester = new ArrayListTest();
	arrayListTester->mainTest();
	LinkedListTest* linkedListTester = new LinkedListTest();
	linkedListTester->mainTest();
	GrafTest* grafTester = new GrafTest();
	grafTester->mainTest();
	system("pause");
	return 0;
}