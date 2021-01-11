#include "contador.h"

void Contador::empezarContador()
{
	int temporizador = seg;
	while (true)
	{
		cout << temporizador << endl;
		Sleep(1000);
		temporizador++;
	}
}