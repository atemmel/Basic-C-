#include "sorted.h"
#include "merge.h"

int main()
{
	std::cout << "The file A1 is ";
	if(!isSorted("A1")) std::cout << "not ";
	std::cout << "sorted." << std::endl;

	if (isSorted("A") && isSorted("B")) merge("A", "B", "C");

	return 0;
}