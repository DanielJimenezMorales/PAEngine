#include "rankingException.h"

RankingException::RankingException()
{
	errorMessage = "E";
	stringstream ss;
	ss << "Error al cargar el ranking\n";
	this->errorMessage = ss.str();
}

const char* RankingException::what() const
{
	return this->errorMessage.c_str();
}