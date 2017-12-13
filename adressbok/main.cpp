#include "contact.h"
#include <iostream>
#include <fstream>

void addContact(const char * fileName);

void searchContact(const char * fileName);

void removeContact(const char * fileName);

void help();

int main(int argc, char* argv[])
{
	const char * fileName = ".contacts";

	std::string input;
	while(std::cin >> input)
	{
		if(input == "exit") 		return 0;
		if(input == "add") 		addContact(fileName);
		else if(input == "search") 	searchContact(fileName);
		else if(input == "remove") 	removeContact(fileName);
		else if(input == "help") 	help();
	}

	return 0;
}

void addContact(const char * fileName)
{
	Contact input;

	std::cin.ignore();
	std::cout << "Write full name: ";
	std::getline(std::cin, input.name);
	std::cout << "Write Adress: ";
	std::getline(std::cin, input.adress);
	std::cout << "Write Email: ";
	std::cin >> input.email;
	std::cout << "Write Phone Number: ";
	std::cin >> input.phoneNr;
	std::cout << "Write Date of Birth (YYYYMMDD): ";
	std::cin >> input.date;
	std::cout << "Write Miscellaneous info: ";
	std::cin.ignore();
	std::getline(std::cin, input.misc);

	std::ofstream output(fileName, std::ios::app);
	output << input;
}

void searchContact(const char * fileName)
{
	std::string input;
	std::cout << "Write searchterm: " << std::endl;
	std::cin >> input;
	
	std::ifstream file(fileName);
		
	Contact contact;
	while(file >> contact) 
	{
		if(contact.contains(input)) std::cout << "Match: " << contact << std::endl;
	}

	std::cin.clear();
}

void removeContact(const char * fileName)
{
	std::cout << "Remove a contact" << std::endl;
}

void help()
{
	std::cout << "Display help here" << std::endl;
}

