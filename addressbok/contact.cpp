#include "contact.h"

const char Contact::ostreamDelimeter 	= '|';
const unsigned int  Contact::nMembers   = 6;

std::string toLower(const std::string & str)
{
	std::string ret;
	for(const auto & c : str) //För varje char i strängen
	{
		if(isupper(c)) ret += tolower(c); //Om den är en versal, lägg till den som en gemen
		else ret += c;	//annars, lägg till den som den är
	}

	return ret;
}

bool Contact::contains(const std::string & term) const
{
	auto comp = toLower(term);	//Gör om strängen till gemener

	//Om strängen går att återfinna någonstans i kontakten, returnera true
	return  toLower(name).find(comp) 	!= -1 ||
		toLower(adress).find(comp) 	!= -1 ||
		toLower(email).find(comp) 	!= -1 ||
		toLower(phoneNr).find(comp) 	!= -1 ||
		toLower(date).find(comp) 	!= -1 ||
		toLower(misc).find(comp) 	!= -1;
}

std::ostream & operator<<(std::ostream & os, const Contact & con)
{
	const char d = Contact::ostreamDelimeter;

	os << con.name  << d << con.adress << d 
		<< con.email << d << con.phoneNr << d 
		<< con.date  << d << con.misc    << d 
		<< '\n';

	return os;
}

std::istream & operator>>(std::istream & is, Contact & con)
{
	const char d = Contact::ostreamDelimeter;
	
	std::string full;
	std::getline(is, full);	//Hämta en rad
	std::string array[Contact::nMembers]; //Bygg upp en array för enkelhetens skull

	for(int i = 0; i < Contact::nMembers; i++) //För varje beståndsdel av en kontakt
	{
		auto f = full.find(d);
		if( f != std::string::npos) //Om det går att hitta ett separationstecken
		{
			array[i] = full.substr(0,f); //Lagra allt från radens början till tecknet
			full = full.substr(f + 1);   //Klipp strängen vid tecknet + 1
		}
		else array[i] = "Could not read data";	//Annars var kontakten korrupt
	}

	//Tilldela kontaktens egenskaper med dess motsvarande slot i arrayen
	con.name 	= array[0];
	con.adress 	= array[1];
	con.email 	= array[2];
	con.phoneNr 	= array[3];
	con.date 	= array[4];
	con.misc 	= array[5];

	//Så länge det finns radbrytningar i strömmen, ignorera dessa
	while(is.peek() == '\n') is.ignore();

	return is;
}
