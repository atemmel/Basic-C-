#include "address_book.h"

void addContact(const char * fileName)
{
        Contact input;
        
        //Mata in stegvis till en kontakt, med respektive filter
        std::cout << "Enter Full name: ";
        filteredInput(input.name, Filter::ALPHA);
        std::cout << "Enter Adress: ";
        filteredInput(input.adress, Filter::ALPHANUMERIC);
        std::cout << "Enter Email: ";
        filteredInput(input.email, Filter::MAIL);
        std::cout << "Enter Phone Number: ";
        filteredInput(input.phoneNr, Filter::NUMERIC);
        std::cout << "Enter Date of Birth (YYYYMMDD): ";
        filteredInput(input.date, Filter::DATE);
        std::cout << "Enter Miscellaneous info: ";
        filteredInput(input.misc, std::string() + Contact::ostreamDelimeter);

        //Lägg till kontakten längst bak i kontaktlistan
        std::ofstream output(fileName, std::ios::app);
        output << input;

        std::cout << "Contact added!" << std::endl;
}

void searchContact(const char * fileName)
{
        std::string input;
        std::cout << "Write searchterm: " << std::endl;
        filteredInput(input, std::string() + Contact::ostreamDelimeter);        //Ta in en sökterm

        std::ifstream file(fileName);

        if(!file.is_open()) //Om filen inte går att öppna, förklara då detta
        {
                std::cout << "The file could not be opened. It might be empty, or open elsewhere" << std::endl;
		return;
        }

        Contact contact;
        unsigned nMatches = 0;
        while(file >> contact) //Så länge kontakter går att hämta ur filströmmen
        {
                //Om kontakten innehåller invärdet, så är det en träff
                if(contact.contains(input))
                {
                        std::cout << "Match: " << contact;
                        ++nMatches;
                }
        }

        std::cout << nMatches << " matches found" << std::endl;
}


void removeContact(const char * fileName)
{
        std::string searchterm;
        std::cout << "Write searchterm for who you wish to remove: " << std::endl;
        filteredInput(searchterm, std::string() +Contact::ostreamDelimeter);    //Ta in en sökterm

        std::ifstream file(fileName);
        std::vector<Contact> contacts;

        unsigned nRemovals = 0;
        Contact contact;
        while(file >> contact)  //Så länge kontakter går att hämta ur filströmmen
        {
                if(contact.contains(searchterm)) //Om kontakten innehåller invärdet
                {
                        //Kolla om användaren vill ta bort personen
                        std::cout << "Match: " << contact << std::endl;
                        std::cout << "Delete this person? (y/n): " << std::endl;

                        std::string input;
                        filteredInput(input, Filter::BOOLEAN);

                        //Om användaren inte vill ta bort kontakten, spara den i listan
                        if(input == "n") contacts.push_back(contact);
			//Öka annars antalet borttagningar
                        else ++nRemovals;
                }
                else contacts.push_back(contact);
                //Annars sökte inte användaren efter kontakten, och den sparas i listan

        }
        file.close();   //Stäng filströmmen så det går att öppna en ny som matar ut istället

        std::ofstream outFile(fileName);
        for(const auto & c : contacts) outFile << c; //Så länge det finns element att mata ut, gör så

        std::cout << nRemovals << " contacts removed" << std::endl;
}

