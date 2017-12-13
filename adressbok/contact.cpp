#include "contact.h"

bool Contact::contains(const std::string & term) const
{	
	if(name.find(term) 		!= -1 ||
		adress.find(term) 	!= -1 ||
		email.find(term) 	!= -1 ||
		phoneNr.find(term) 	!= -1 ||
		date.find(term) 	!= -1 ||
		misc.find(term) 	!= -1)
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
