#include "sorted.h"

bool isSorted(const char * fileName)
{
	std::ifstream file(fileName);
	int current, previous;
	file >> current;
	previous = current;

	while (file >> current)
	{
		if (current < previous) return 0;
		previous = current;
	}

	return 1;
}
