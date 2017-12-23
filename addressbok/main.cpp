#include "address_book.h"

//Visar hjälptext
void help();

int main(int argc, char* argv[])
{
	const char * fileName = ".contacts";	//Filnamnet för kontakterna
	
	std::cout << "Welcome to the address book! For help type 'help'." << std::endl; 

	std::string input;
	while(getline(std::cin, input))
	{
		input = toLower(input);		//Omvandla strängen till gemener

		if(input == "exit") 		return 0;			//Avsluta
		if(input == "add") 		addContact(fileName);		//Lägg till kontakt
		else if(input == "search") 	searchContact(fileName);	//Sök efter kontakt
		else if(input == "remove") 	removeContact(fileName);	//Radera kontakt
		else if(input == "help") 	help();				//Visa hjälptext
		else std::cout << "Unrecognized command, for help type 'help'." << std::endl;
	}

	return 0;
}

void help()
{
	//Skriv ut generell hjälptext om vilka kommandon som finns tillgängliga
	std::cout << "add    | Add a person to the address book."	<< std::endl;
	std::cout << "search | Search for an already existing person." 	<< std::endl;
	std::cout << "remove | Remove an already existing person."	<< std::endl;
	std::cout << "help   | Display this help text."			<< std::endl;
	std::cout << "exit   | Exit the program."			<< std::endl;
}

