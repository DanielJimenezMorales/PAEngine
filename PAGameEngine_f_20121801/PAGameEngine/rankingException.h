#pragma once
#include <exception>
#include <string>
#include <sstream>

using namespace std;

class RankingException : public exception
{
	string errorMessage;
public:
	RankingException();
	~RankingException() {}
	virtual const char* what() const;
};

