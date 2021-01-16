#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "filaRanking.h"

using namespace std;

class Ranking
{
	int sizeOfArray = 5;
	int rankingPoints[5];
	vector<FilaRanking*> filas;
public:
	Ranking()
	{
		initRanking();
	}

	int getRankingPoints(int pos) { return this->filas[pos]->getTotalPoints(); }

	void initRanking();
	void addRow(FilaRanking* newRow) { this->filas.push_back(newRow); };
	FilaRanking* getRow(int pos) { return filas[pos]; }
	bool escrituraEnRanking(string fileName);
	void lecturaEnRanking(string fileName);
	string showRanking();
	void sortRanking(string playerName, int newPoints); //Ordenar ranking
	void sortArray(FilaRanking* newPoints);
};
