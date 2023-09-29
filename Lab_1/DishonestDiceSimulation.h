#pragma once
#include<string>
#include"ArrayList.h"
#include"Dice.h"
class DishonestDiceSimulation
{
private:
	int maxPossibleSumm();
	void computeSumms(List<long double>* amountSumms,
		int diceNomer,int curSumm, long double curProb);
	void createSimulationFromFile(std::string fileName);
	long double wordToNumber(std::string word, bool* isCorrectWord);
	ArrayList<Dice*>* dices;
public:
	DishonestDiceSimulation(Dice* dice);
	DishonestDiceSimulation(List<Dice*>* diceList);
	DishonestDiceSimulation(std::string fileName);
	~DishonestDiceSimulation();
	List<Dice*>* getDices();
	void addDice(Dice* dice);
	void printDices();
	void printSummProbabilitiesInFile(std::string fileName);
	List<long double>* summProbabilities();
	std::string toString();
};

