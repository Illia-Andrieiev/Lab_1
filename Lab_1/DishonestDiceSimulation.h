#pragma once
#include"ArrayList.h"
#include"Dice.h"
class DishonestDiceSimulation
{
private:
	int maxPossibleSumm();
	void computeSumms(List<long double>* amountSumms,
		int diceNomer,int curSumm, long double curProb);
	ArrayList<Dice*>* dices;
public:
	DishonestDiceSimulation(Dice* dice);
	DishonestDiceSimulation(List<Dice*>* diceList);
	~DishonestDiceSimulation();
	List<Dice*>* getDices();
	void addDice(Dice* dice);
	void printDices();
	List<long double>* summProbabilities();
};

