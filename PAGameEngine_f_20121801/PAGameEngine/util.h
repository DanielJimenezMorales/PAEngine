#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Util
{
	inline double getRand(double min, double max) {
		static const int PRECISION = 10000;
		double n = max - min;
		int ir = rand() % PRECISION;
		double r = min + (double)ir / PRECISION * n;
		return r;
	}

	inline double getRand(double max = 1) { return getRand(0, max); }

	vector<string> split0(string line) {
		string word;
		vector<string> words;
		istringstream ss(line);
		while (cin >> word) {
			words.push_back(word);
		}
		return words;
	}

	vector<string> split(string line, char delim = ' ') {
		string word;
		vector<string> words;
		istringstream ss(line);
		while (getline(ss, word, delim)) {
			words.push_back(word);
		}
		return words;
	}
};

