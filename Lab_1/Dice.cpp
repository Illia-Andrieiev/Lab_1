#include "Dice.h"
#include <iostream>
// Constructor
Dice::Dice(long double* probabilities, int size) {
	if (isCorrectProbabilities(probabilities, size)) {
		std::cout << "Summ of edges probabilities more than 1 or have probability < 0";
		this->probabilities = new ArrayList<long double>();
	}
	else {
		this->probabilities = new ArrayList<long double>(probabilities, size);
	}
}
// Check if summ of probabilities more then 1 or at least one < 0.
bool Dice::isCorrectProbabilities(long double* probabilities, int size) {
	long double summ = 0;
	for (int i = 0; i < size; i++) {
		if (probabilities[i] < 0)
			return false;
		summ += probabilities[i];
	}
	return summ > 1 ? false : true;
}
// Change probabilities, if they are correct
void Dice::changeProbabilitiesAndEdges(long double* probabilities, int size) {
	if (isCorrectProbabilities(probabilities, size)) {
		std::cout << "Summ of edges probabilities more than 1 or have probability < 0";
	}
	else {
		this->probabilities->clear();
		this->probabilities->addAll(probabilities, size);
	}
}