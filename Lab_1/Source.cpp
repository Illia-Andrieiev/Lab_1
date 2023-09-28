#include "Graf.cpp"
#include "ArrayList.cpp"
#include "LinkedList.cpp"
#include "ArrayListTest.h"
#include "LinkedListTest.h"
#include "GrafTest.h"
#include "Dice.h"
#include "DishonestDiceSimulation.h"
using namespace std;
int main() {
	//ArrayListTest* arrayListTester = new ArrayListTest();
	//arrayListTester->mainTest();
	//LinkedListTest* linkedListTester = new LinkedListTest();
	//linkedListTester->mainTest();
	//GrafTest* grafTester = new GrafTest();
	//grafTester->mainTest();
	long double coin[] = { 0.5,0.5 };
	long double dishonest[] = { 0.1,0.4,0.5 };
	long double cube[] = { 0.166666,0.166666,0.166666,0.166666,0.166666,0.166666, };
	Dice* coin1 = new Dice(coin,2);
	coin1->getProbabilities()->print();
	Dice* coin2 = new Dice(coin, 2);
	coin2->getProbabilities()->print();
	Dice* cube1 = new Dice(cube, 6);
	cube1->getProbabilities()->print();
	Dice* cube2 = new Dice(cube, 6);
	Dice* cube3 = new Dice(cube, 6);
	Dice* unHon = new Dice(dishonest, 3);
	cube2->getProbabilities()->print();
	DishonestDiceSimulation* simulation1 = new DishonestDiceSimulation(coin1);
	simulation1->addDice(coin2);
	simulation1->addDice(coin2);
	simulation1->addDice(coin2);
	DishonestDiceSimulation* simulation2 = new DishonestDiceSimulation(cube1);
	simulation2->addDice(cube2);
	simulation2->addDice(cube3);
	simulation2->addDice(unHon);
	simulation2->addDice(unHon);
	simulation2->addDice(unHon);
	simulation2->addDice(unHon);
	simulation2->addDice(coin1);
	simulation2->addDice(cube3);
	simulation2->addDice(coin1);
	simulation2->addDice(coin1);
	simulation2->addDice(coin2);
	cout << "*******************************************************" << endl;
	List<long double>* summ1 = simulation1->summProbabilities();
	summ1->print();
	cout << "*******************************************************" << endl;
	List<long double>* summ2 = simulation2->summProbabilities();
	summ2->print();
	long double res = 0;
	for (int i = 0; i < summ2->size(); i++) {
		res += summ2->get(i);
	}
	cout << endl << res;
	system("pause");
	return 0;
}