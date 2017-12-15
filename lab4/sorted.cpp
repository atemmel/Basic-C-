#include "sorted.h"

//Adam Temmel
//2017-12-15
//Introduktion till programmering i C++
//Lab 4

bool isSorted(const char * fileName)
{
	std::ifstream file(fileName);	//Öppna filen
	int current, previous;
	file >> current;	//Ge variablerna startvärden
	previous = current;

	while (file >> current)	//Så länge det går att plocka ifrån filen
	{
		if (current < previous) return 0; //Skulle det nya värdet någonsin vara mindre än det gamla så är filen inte sorterad, returnera false
		previous = current;	//Skriv över det gamla värdet med det nya värdet
	}

	return 1; //Om funktionen klarat sig hit så har den gått igenom samtliga tecken i filen, och filen är därför sorterad
}
