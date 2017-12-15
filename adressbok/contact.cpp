#include "contact.h"

std::string toLower(const std::string & str)
{
	std::string ret;
	for(const auto & c : str)
	{
		if(isupper(c)) ret += tolower(c);
		else ret += c;
	}

	return ret;
}

bool Contact::contains(const std::string & term) const
{
	auto comp = toLower(term);
	if(toLower(name).find(comp) 		!= -1 ||
		toLower(adress).find(comp) 	!= -1 ||
		toLower(email).find(comp) 	!= -1 ||
		toLower(phoneNr).find(comp) 	!= -1 ||
		toLower(date).find(comp) 	!= -1 ||
		toLower(misc).find(comp) 	!= -1)
		return 1;

	return 0;
}

std::ostream & operator<<(std::ostream & os, const Contact & con)
{
	const char d = '/';
	os << con.name  << d << con.adress << d 
		<< con.email << d << con.phoneNr << d << con.date << d << con.misc << d;

	return os;
}

std::istream & operator>>(std::istream & is, Contact & con)
{
	const char d = '/';

	std::getline(is, con.name, d);
	std::getline(is, con.adress, d);
	std::getline(is, con.email, d);
	std::getline(is, con.phoneNr, d);
	std::getline(is, con.date, d);
	std::getline(is, con.misc, d);
	
	return is;
}
