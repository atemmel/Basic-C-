#include "contact.h"
#include <fstream>

void filteredInput(std::string & input);

void addContact(const char * fileName);

void searchContact(const char * fileName);

void removeContact(const char * fileName);

void help();

int main(int argc, char* argv[])
{
	const char * fileName = ".contacts";
	
	std::cout << "Welcome to the address book! For help type 'help'." << std::endl; 

	std::string input;
	while(getline(std::cin, input))
	{
		input = toLower(input);
		if(input == "exit") 		return 0;
		if(input == "add") 		addContact(fileName);
		else if(input == "search") 	searchContact(fileName);
		else if(input == "remove") 	removeContact(fileName);
		else if(input == "help") 	help();
		else std::cout << "Unrecognized command, for help type 'help'." << std::endl;
	}

	return 0;
}

void filteredInput(std::string & input)
{
	bool valid = 0, failed = 0;
	while(!valid)
	{
		if(failed) std::cout << "Please refrain from using symbols." << std::endl;
		std::getline(std::cin, input);
		std::string tmp;
		for(const auto & c : input) if(c != '/') tmp += c;
		valid = tmp == input;
		failed = 1;
	}
	
	
}

void addContact(const char * fileName)
{
	Contact input;

	std::cout << "Write full name: ";
	filteredInput(input.name);
	std::cout << "Write Adress: ";
	filteredInput(input.adress);
	std::cout << "Write Email: ";
	filteredInput(input.email);
	std::cout << "Write Phone Number: ";
	filteredInput(input.phoneNr);
	std::cout << "Write Date of Birth (YYYYMMDD): ";
	filteredInput(input.date);
	std::cout << "Write Miscellaneous info: ";
	filteredInput(input.misc);

	std::ofstream output(fileName, std::ios::app);
	output << input;
}

void searchContact(const char * fileName)
{
	std::string input;
	std::cout << "Write searchterm: " << std::endl;
	filteredInput(input);

	std::ifstream file(fileName);
		
	Contact contact;
	while(file >> contact) 
	{
		if(contact.contains(input)) std::cout << "Match: " << contact << std::endl;
	}

}

void removeContact(const char * fileName)
{
	std::string searchterm;
	std::cout << "Write searchterm for who you wish to delete: " << std::endl;
	filteredInput(searchterm);

	std::ifstream file(fileName);

	Contact contact;
	while(file >> contact)
	{
		if(contact.contains(searchterm)) 
		{
			std::cout << "Match: " << contact << std::endl;
			std::cout << "Delete this person? (y/n): " << std::endl;

			std::string input;
			while(input != "y" && input != "n") filteredInput(input);
		}
		
	}
}

void help()
{
	std::cout << "add    | Add a person to the address book."	<< std::endl;
	std::cout << "search | Search for an already existing person." 	<< std::endl;
	std::cout << "remove | Remove an already existing person."	<< std::endl;
	std::cout << "help   | Display this help text."			<< std::endl;
	std::cout << "exit   | Exit the program."			<< std::endl;
}

