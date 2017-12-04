#include "merge.h"

void merge(char * file1, char * file2, char * result)
{
	std::ifstream fileA(file1), fileB(file2);
	std::ofstream fileC(result);
	
	int a, b, c;

	while (fileA >> a && fileB >> b)
	{
		a < b ? c = a : c = b;
		fileC << c << ' ';
	}

	while (fileA >> c) fileC << c << ' ';
	while (fileB >> c) fileC << c << ' ';
}
