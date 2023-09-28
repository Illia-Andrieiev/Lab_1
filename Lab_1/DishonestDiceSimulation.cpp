#include "DishonestDiceSimulation.h"
#include"ArrayList.cpp"
//******************************************************************
/*
						   PRIVATE METHODS
*/
//******************************************************************
// Find max possible summ for toss
int DishonestDiceSimulation::maxPossibleSumm() {
	int maxSumm = 0;
	for (int i = 0; i < dices->size(); i++)
		maxSumm += dices->get(i)->getProbabilities()->size();
	return maxSumm;
}
// Find probability for each edges summ for toss 
void DishonestDiceSimulation::computeSumms(List<long double>* amountSumms, 
	int diceNomer, int curSumm, long double curProb) {
	if (diceNomer == dices->size() - 1) { // If it`s last dice add probability of this toss to cur summ
		int diseEdges = dices->get(diceNomer)->getProbabilities()->size(); // amount of edges
		for (int i = 1; i <= diseEdges; i++) { // for each edge
			int positionToIncrees = curSumm + i; // summ after toss
			long double probToAdd = curProb * dices->get(diceNomer)->getProbabilities()->get(i - 1); // Probability of this toss
			amountSumms->set(amountSumms->get(positionToIncrees) + probToAdd, positionToIncrees); // Add to summ
		}
	}
	else {
		int diseEdges = dices->get(diceNomer)->getProbabilities()->size(); // amount of adges
		for (int i = 1; i <= diseEdges; i++) { // for each edge
			int positionToIncrees = curSumm + i; // summ at current moment
			// Probability of that toss at current moment
			long double probToAdd = curProb * dices->get(diceNomer)->getProbabilities()->get(i - 1);
			// Recursion for each next dice
			computeSumms(amountSumms, diceNomer + 1, curSumm + i, probToAdd);
		}
	}
}
//******************************************************************
/*
							PUBLIC METHODS
*/
//******************************************************************
// Constructors
DishonestDiceSimulation::DishonestDiceSimulation(Dice* dice) {
	dices = new ArrayList<Dice*>();
	dices->pushBack(dice);
};
DishonestDiceSimulation::DishonestDiceSimulation(List<Dice*>* diceList) {
	dices = new ArrayList<Dice*>();
	dices->addAll(diceList);
};
// Destructor
DishonestDiceSimulation::~DishonestDiceSimulation() {
	dices->clear();
};
// Return List of dices
List<Dice*>* DishonestDiceSimulation::getDices() {
	return dices;
};
// Add dice to 
void DishonestDiceSimulation::addDice(Dice* dice) {
	dices->pushBack(dice);
};
// Print all Dices
void DishonestDiceSimulation::printDices() {
	for (int i = 0; i < dices->size(); i++) {
		std::cout << "Dice nomber " << i << ": ";
		dices->get(i)->getProbabilities()->print();
	}
} 
// Return list with probabilities for each edges summ for a toss  
List<long double>* DishonestDiceSimulation::summProbabilities() {
	List<long double>* res = new ArrayList<long double>();
	int maxSumm = maxPossibleSumm();
	for (int i = 0; i <= maxSumm; i++)
		res->pushBack(0);
	computeSumms(res, 0, 0, 1);
	return res;
}