#pragma once

#include <string>
using namespace std;

class FilaRanking
{
	string name;
	int totalPoints;
public:
	FilaRanking(string pn, int tp = 0) : name(pn), totalPoints(tp) {}
	string getPlayerName() { return this->name; }
	void setName(string newName) { this->name = newName; }
	int getTotalPoints() { return this->totalPoints; }
	void setTotalPoints(int newPoints) { this->totalPoints = newPoints; }
};

