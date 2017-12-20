#include "contact.h"
#include <fstream>
#include <vector>

//Tar bort delimetertecknet ur strängar som kommer in
void filteredInput(std::string & input);

//Lägger till kontakter till filen
void addContact(const char * fileName);

//Söker efter kontakter i filen
void searchContact(const char * fileName);

//Tar bort kontakter ur filen
void removeContact(const char * fileName);

//Visar hjälptext
void help();

int main(int argc, char* argv[])
{
	const char * fileName = ".contacts";	//Filnamnet för kontakterna
	
	std::cout << "Welcome to the address book! For help type 'help'." << std::endl; 

	std::string input;
	while(getline(std::cin, input))
	{
		input = toLower(input);	//Omvandla strängen till små bokstäver
		if(input == "exit") 		return 0;		//Avsluta
		if(input == "add") 		addContact(fileName);	//Lägg till kontakt
		else if(input == "search") 	searchContact(fileName);//Sök efter kontakt
		else if(input == "remove") 	removeContact(fileName);//Radera kontakt
		else if(input == "help") 	help();			//Visa hjälptext
		else std::cout << "Unrecognized command, for help type 'help'." << std::endl;
	}

	return 0;
}

void filteredInput(std::string & input)
{
	bool valid = 0, failed = 0;
	while(!valid)
	{
		//Visa felmeddelande om användaren misslyckats med en korrekt inmatning en gång
		if(failed) std::cout << "Please refrain from using symbols." << std::endl;
		std::getline(std::cin, input);
		std::string tmp;
		for(const auto & c : input) if(c != '/') tmp += c; //Om tecknet inte är '/', lägg då till den
		valid = tmp == input;	//Valid tilldelas likheten mellan tmp och inmatningen
		failed = 1;		//Börja mata ut hjälptext
	}
	
	
}

void addContact(const char * fileName)
{
	Contact input;
	
	//Mata in stegvis till en kontakt
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

	//Lägg till kontakten längst bak i kontaktlistan
	std::ofstream output(fileName, std::ios::app);
	output << input;
}

void searchContact(const char * fileName)
{
	std::string input;
	std::cout << "Write searchterm: " << std::endl;
	filteredInput(input);	//Ta in en sökterm

	std::ifstream file(fileName);
	
	if(!file.is_open())
	{
		std::cout << "File could not be opened. Try again." << std::endl;
		return;
	}
	else if(file.eof())
	{
		std::cout << "File was empty. Try adding some contacts first!" << std::endl;
	}

	Contact contact;
	while(file >> contact) //Så länge kontakter går att hämta ur filströmmen
	{
		//Om kontakten innehåller invärdet, så är det en träff
		if(contact.contains(input)) std::cout << "Match: " << contact << std::endl;
	}

}

void removeContact(const char * fileName)
{
	std::string searchterm;
	std::cout << "Write searchterm for who you wish to delete: " << std::endl;
	filteredInput(searchterm);	//Ta in en sökterm

	std::ifstream file(fileName);
	std::vector<Contact> contacts;

	Contact contact;
	while(file >> contact)	//Så länge kontakter går att hämta ur filströmmen
	{
		if(contact.contains(searchterm)) //Om kontakten innehåller invärdet
		{
			//Kolla om användaren vill ta bort personen
			std::cout << "Match: " << contact << std::endl;
			std::cout << "Delete this person? (y/n): " << std::endl;

			//Hämta inmatningar tills någon utav dem är 'y' eller 'n'
			std::string input;
			while(input != "y" && input != "n") filteredInput(input);

			//Om användaren inte vill ta bort kontakten, spara den i listan
			if(input == "n") contacts.push_back(contact);
		}
		else contacts.push_back(contact);
		//Annars sökte inte användaren efter kontakten, och den sparas i listan
		
	}
	file.close();	//Stäng filströmmen så det går att öppna en ny som matar ut istället

	std::ofstream outFile(fileName);
	for(const auto & c : contacts) outFile << c; //Så länge det finns element att mata ut, gör så
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

