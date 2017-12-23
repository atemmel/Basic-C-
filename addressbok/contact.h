#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

/**
 *	Tar bort alla versaler ur en sträng och ersätter de med gemener.
 *
 *	@param str Den sträng som skall konverteras
 *	@return En sträng utan gemener
 */
std::string toLower(const std::string & str);

/**
 *	En struct för att uttrycka en kontakt i adressboken samt
 *	tillgodose användbara metoder.
 */
struct Contact {

	/**
	 *	Kontrollerar huruvida en term går att återfinna 
	 *	inuti en kontakt.
	 *
	 *	@param term Den term som skall sökas efter
	 *	@return True om termen hittades i kontakten.
	 */
	bool contains(const std::string & term) const;
		
	std::string name;	//Namn
	std::string address;	//Adress
	std::string email;	//Epostadress
	std::string phoneNr;	//Telefonnummer
	std::string date;	//Födelsedatum
	std::string misc;	//Övrigt

	const static char ostreamDelimeter; //Ett separeringstecken för att åtskilja kontakter
	const static unsigned nMembers; //Antalet medlemmar till en kontakt
};

/**
 *	In och utströmsfunktioner för kontaktstructen
 */
std::ostream & operator<<(std::ostream &, const Contact &);
std::istream & operator>>(std::istream &, Contact &);

#endif
