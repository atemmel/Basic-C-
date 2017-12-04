#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream file("names.txt");
	std::string firstName, surName, personId, adress;

	while (std::getline(file, firstName, ' '))
	{
		std::getline(file, surName);
		std::getline(file, personId);
		std::getline(file, adress);
		
		std::string gender = " [%]";
		(static_cast<int>(personId[8]) - '0') % 2 == 0 ? gender[2] = 'F' : gender[2] = 'M';

		std::cout << surName << ", " << firstName << gender << std::endl;
		std::cout << adress << std::endl;
	}

	return 0;
}

