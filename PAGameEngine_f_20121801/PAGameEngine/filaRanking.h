#pragma once

#include <string>
using namespace std;

class FilaRanking
{
	string playerName;
	int totalPoints;
public:
	FilaRanking(string pn, int tp) : playerName(pn), totalPoints(tp) {}
	string getPlayerName() { return this->playerName; }
	int getTotalPoints() { return this->totalPoints; }
	void setTotalPoints(int newPoints) { this->totalPoints = newPoints; }
};

