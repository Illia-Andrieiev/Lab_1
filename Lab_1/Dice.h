#pragma once
#include"ArrayList.h"
class Dice
{
private:
	ArrayList<long double>* probabilities;
	bool isCorrectProbabilities(long double* probabilities, int size);
public:
	Dice(long double* probabilities, int size);
	void changeProbabilitiesAndEdges(long double* probabilities, int size);
};

