#include "sorted.h"
#include "merge.h"

//Adam Temmel
//2017-12-15
//Introduktion till programmering i C++
//Lab 4

int main()
{
	std::cout << "The file A1 is ";
	if(!isSorted("A1")) std::cout << "not "; //Kontrollera om filen A1 är sorterad
	std::cout << "sorted." << std::endl;

	if (isSorted("A") && isSorted("B")) merge("A", "B", "C"); //Om A och B är sorterad, merga dessa till C

	return 0;
}
