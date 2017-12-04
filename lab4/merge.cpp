#include "merge.h"

void merge(const char * file1, const char * file2, const char * result)
{
	std::ifstream fileA(file1), fileB(file2);
	std::ofstream fileC(result);
	
	int a, b, c;

	fileA >> a;
	fileB >> b;

	while (!fileA.eof() && !fileB.eof())
	{
		if(a < b)
		{
			c = a;
			fileA >> a;
		}
		else
		{
			c = b;
			fileB >> b;
		}
		
		fileC << c << ' ';
	}

	while (fileA >> c) fileC << c << ' ';
	while (fileB >> c) fileC << c << ' ';
}
