#pragma once
#include<iostream>
#include<chrono>
#include"List.h"
#include"DishonestDiceSimulation.h"
#include"Dice.h"
class SimulationBenchmarking
{
private:
	DishonestDiceSimulation* simulation;
public:
	SimulationBenchmarking() {
		long double coin[] = { 0.5,0.5 };
		long double dishonest[] = { 0.1,0.4,0.5 };
		long double cube[] = { 0.166666,0.166666,0.166666,0.166666,0.166666,0.166666, };
		Dice* coinD = new Dice(coin, 2);
		simulation = new DishonestDiceSimulation(coinD);
		Dice* cubeD = new Dice(cube, 6);
		Dice* unHonD = new Dice(dishonest, 3);
		simulation->addDice(cubeD);
		simulation->addDice(cubeD);
		simulation->addDice(unHonD);
		simulation->addDice(unHonD);
		simulation->addDice(coinD);
		simulation->addDice(coinD);
	}
	void microBenchmarking(int n) {
		uint64_t startSec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		for (int i = 0; i < n; i++) {
			List<long double>* summ = simulation->summProbabilities();
		}
		uint64_t endSec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << (double_t)endSec - (double_t)startSec << " seconds for " << n << " cycles" << std::endl;
	}
};

