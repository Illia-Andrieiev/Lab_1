#include<string>
#include<fstream>
#include"DishonestDiceSimulation.h"
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
// return long double from word
long double DishonestDiceSimulation::wordToNumber(std::string word, bool* isCorrectWord) {
	long double res = 0;
	long double manticeMultipl = 0.1;
	bool isVievedComa = false; // true if we saw coma or dot in word
	for (int i = 0; i < word.length(); i++) { // For each character
		if (word[i] != ' ' && word[i] != '\t' && word[i] != '\n') { // If not gaps
			if ((int)word[i] < 48 || (int)word[i] > 57) { // if not nomber
				if (((int)word[i] == 46 || (int)word[i] == 44) && !isVievedComa)
					isVievedComa = true; // if '.' || ',' true
				else {
					*isCorrectWord = false; // Uncorrect data
					return 0;
				}
			}
			else {
				if (!isVievedComa) // If doesn`t see ',' || '.' add before dot
					res = res * 10 + (int)word[i] - 48;
				else { // Add after dot
					res = res + ((int)word[i] - 48) * manticeMultipl;
					manticeMultipl *= 0.1;
				}
			}
		}
	}
	*isCorrectWord = true;
	return res;
}
// Create simulation reading file
/*
	File must store data in next format: 
	(amount_of_dice_edges [probability for each edge nomers starts from 1 to amount_of_dice_edges ]*)*
	 - * mean iteration of expression. For example 3 0.5 0.2 0.3 2 0.5 0.5 data mean:
	 Dice1: probability to get 1 = 0.5, to get 2 = 0.2, to get 3 = 0.3
	 Dice2: probability to get 1 = 0.5, to get 2 = 0.5.
*/
void  DishonestDiceSimulation::createSimulationFromFile(std::string fileName) {
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		std::cout << "File can`t be opened." << std::endl;
	}
	else {
		int counter = 0; // amount edges in dice
		bool first = true; // Is first iteration
		std::string word; // current word 
		List<long double>* list = new ArrayList<long double>();
		while (!file.eof()) {
			word = "";
			file >> word;
			bool* isCorrectWord = new bool; // check is word correct	
			if(counter == 0){ // If all edges for dice read, add dice to simulation
				if (!first) {
					Dice* newDice = new Dice(list);
					dices->pushBack(newDice);
					list->clear();
				}
				else {
					first = false;
				}
				long double fff = wordToNumber(word, isCorrectWord);
				counter = (int)fff;// find amount new dice edges
				if (!*isCorrectWord) {
					delete isCorrectWord;
					std::cout << "File contains uncorrect nombers." << std::endl;
					return;
				}
			}
			else { // add edge to edgesList for dice
				--counter;
				long double fff = wordToNumber(word, isCorrectWord);
				list->pushBack(fff);
				if (!*isCorrectWord) {
					delete isCorrectWord;
					std::cout << "File contains uncorrect nombers." << std::endl;
					return;
				}
			}
			delete isCorrectWord;
		}
		//Create last dice
		Dice* newDice = new Dice(list);
		dices->pushBack(newDice);
		list->clear();
	}
	file.close();
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
DishonestDiceSimulation::DishonestDiceSimulation(std::string fileName) {
	dices = new ArrayList<Dice*>();
	createSimulationFromFile(fileName);
}
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
void DishonestDiceSimulation::printSummProbabilitiesInFile(std::string fileName) {
	std::ofstream file;
	file.open(fileName);
	if (!file.is_open()) {
		std::cout << "File can`t be created." << std::endl;
	}
	else {
		List<long double>* summ = summProbabilities();
		for (int i = 0; i < summ->size(); i++) {
			if(summ->get(i) != 0)
				file << "Probability to get " << i << " in summ is: " << summ->get(i) << "\n";
		}
	}
	file.close();
}