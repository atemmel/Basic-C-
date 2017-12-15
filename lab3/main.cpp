#include <iostream>
#include <string>
#include <fstream>

//Adam Temmel
//2017-12-15
//Introduktion till programmering i C++
//Laboration 3

int main()
{
	std::ifstream file("names.txt"); //Öppna filen
	std::string firstName, surName, personId, adress;

	while (std::getline(file, firstName, ' ')) //Hämta tills nästa mellanslag in i variabeln firstname
	{
		std::getline(file, surName);	//Hämta tills nästa newline och stoppa resultatet i avsedd variabel
		std::getline(file, personId);
		std::getline(file, adress);
		
		std::string gender = " [%]";	//Skapa en sträng för könet
		//Casta nionde tecknet till ett heltal och subtrahera med asciivärdet för tecknet '0', nu kommer värdet att ligga mellan 0-9
		//Om divison med två ej ger rest är personen kvinna, annars man, så ersätt tredje tecknet med 'F' respektive 'M'
		(static_cast<int>(personId[8]) - '0') % 2 == 0 ? gender[2] = 'F' : gender[2] = 'M';

		//Skriv ut resultaten
		std::cout << surName << ", " << firstName << gender << std::endl;
		std::cout << adress << std::endl;
	}

	return 0;
}

