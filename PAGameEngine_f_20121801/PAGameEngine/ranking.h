#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "filaRanking.h"
#include "rankingException.h"

using namespace std;

class Ranking
{
	int sizeOfArray = 5;
	int rankingPoints[5];
	vector<FilaRanking*> filas;

	FilaRanking* playerRow;

public:
	Ranking()
	{
		playerRow = new FilaRanking("USER", 0);
		initRanking();
	}

	~Ranking() {
		for (FilaRanking* fl : filas)
		{
			delete fl;
		}
		filas.clear();
		delete playerRow;
	}

	int getRankingPoints(int pos) { return this->filas[pos]->getTotalPoints(); }
	void setPlayerName(string newName) { this->playerRow->setName(newName); }
	int getPlayerPoints() { return this->playerRow->getTotalPoints(); }
	void setPlayerPoints(int newPoints) { this->playerRow->setTotalPoints(newPoints); }

	void initRanking();
	void addRow(FilaRanking* newRow) { this->filas.push_back(newRow); };
	FilaRanking* getRow(int pos) { return filas[pos]; }
	void escrituraEnRanking(string fileName);
	void lecturaEnRanking(string fileName);
	void sortRanking();
	void sortArray(FilaRanking* newPoints);
};
