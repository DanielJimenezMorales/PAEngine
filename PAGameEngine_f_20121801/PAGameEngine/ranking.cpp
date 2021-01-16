#include "ranking.h"

void Ranking::initRanking()
{
	lecturaEnRanking("ranking.txt");
	for (int i = 0; i < filas.size(); i++)
	{
		cout << filas[i]->getPlayerName() << endl;
		cout << filas[i]->getTotalPoints() << endl;
	}
}

bool Ranking::escrituraEnRanking(string fileName)
{
	bool success = true;
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
		success = false;
		cout << "ERROR" << endl;
	}
	return success;
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
		cout << "ERROR" << endl;
	}
}

string Ranking::showRanking()
{
	string output = "";
	for (int i = 0; i < sizeOfArray; i++)
	{
		output += " " + to_string(rankingPoints[i]);
	}
	return output;
}

void Ranking::sortRanking()
{
	sortArray(playerRow);

	/*for (int i = 0; i < output.size(); i++)
	{
		rankingPoints[i] = output2[i];
	}*/
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