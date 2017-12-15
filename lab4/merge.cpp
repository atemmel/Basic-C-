#include "merge.h"

//Adam Temmel
//2017-12-15
//Introduktion till programmering i C++
//Lab 4

void merge(const char * file1, const char * file2, const char * result)
{
	std::ifstream fileA(file1), fileB(file2); //Öppna alla filer som behövs
	std::ofstream fileC(result);
	
	int a, b, c;

	fileA >> a;	//Ge variablerna ett startvärde
	fileB >> b;

	while (!fileA.eof() && !fileB.eof())	//Så länge ingen utav filerna är tomma
	{
		if(a < b)	//Om a är minst, tilldela c värdet på a
		{
			c = a;
			fileA >> a;	//Ge a ett nytt värde ifrån motsvarande fil
		}
		else
		{
			c = b;	//Tilldela annars c värdet på b och ge b ett nytt värde ifrån motsvarande fil
			fileB >> b;
		}
		
		fileC << c << ' ';	//c har nu det minsta värdet tillgängligt, och matas därför in i resultatfilen
	}

	//Slutligen, kolla om den andra filen har tecken kvar i sig, i så fall, mata dessa till resultatfilen
	while (fileA >> c) fileC << c << ' ';
	while (fileB >> c) fileC << c << ' ';
}
