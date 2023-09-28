#pragma once
#include"ArrayList.h"
class Dice
{
private:
	List<long double>* probabilities;
	bool isCorrectProbabilities(long double* probabilities, int size);
	bool isCorrectProbabilities(List<long double>* list);
public:
	Dice(long double* probabilities, int size);
	Dice(List<long double>* list);
	void changeProbabilitiesAndEdges(long double* probabilities, int size);
	List<long double>* getProbabilities();
};

