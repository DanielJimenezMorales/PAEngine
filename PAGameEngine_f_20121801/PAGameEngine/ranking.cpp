#include "ranking.h"

void Ranking::initRanking()
{
	lecturaEnRanking("ranking.txt");
}

void Ranking::escrituraEnRanking(string fileName)
{
	ofstream fFicheroTextoEscritura(fileName);
	if (fFicheroTextoEscritura.is_open())
	{
		for (int i = 0; i < filas.size(); i++)
		{
			fFicheroTextoEscritura << this->filas[i]->getPlayerName() + " " + to_string(this->filas[i]->getTotalPoints()) + " ";
		}
		fFicheroTextoEscritura.close();
	}
	else
	{
		throw RankingException();
	}
}

void Ranking::lecturaEnRanking(string fileName)
{
	vector<string> output;
	string line;
	ifstream fFicheroTextoLectura(fileName);
	if (fFicheroTextoLectura.is_open())
	{
		int contador = 0;
		int contador2 = 0;
		while (getline(fFicheroTextoLectura, line, ' '))
		{
			if (contador % 2 == 0)
			{
				string name = line;
				FilaRanking* newRow = new FilaRanking(name, 0);
				this->filas.push_back(newRow);
			}
			else
			{
				this->filas[contador2]->setTotalPoints(stoi(line));
				contador2++;
			}
			contador++;
		}
		fFicheroTextoLectura.close();
	}
	else
	{
		throw RankingException();
	}
}

void Ranking::sortRanking()
{
	sortArray(playerRow);
}

void Ranking::sortArray(FilaRanking* newPoints)
{
	vector<FilaRanking*> provisional = filas;

	provisional.push_back(newPoints);

	FilaRanking* aux;
	int j, i;
	for (int i = 0; i < provisional.size() - 1; i++)
	{
		for (int j = 0; j < provisional.size() - 1 - i; j++)
		{
			if (provisional[j]->getTotalPoints() < provisional[j + 1]->getTotalPoints())
			{
				aux = provisional[j];
				provisional[j] = provisional[j + 1];
				provisional[j + 1] = aux;
			}
		}
	}

	provisional.pop_back();

	this->filas = provisional;
}