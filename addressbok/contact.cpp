#include "contact.h"

const char Contact::ostreamDelimeter 	= '|';
const unsigned int  Contact::nMembers   = 6;

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
		<< con.email << d << con.phoneNr << d << con.date 
		<< d << con.misc << d << '\n';

	return os;
}

std::istream & operator>>(std::istream & is, Contact & con)
{
	const char d = Contact::ostreamDelimeter;

	
	std::string full;
	std::getline(is, full);
	std::string array[Contact::nMembers];

	for(int i = 0; i < Contact::nMembers; i++)
	{
		auto f = full.find(d);
		if( f != std::string::npos)
		{
			array[i] = full.substr(0,f);
			full = full.substr(f + 1);
		}
		else array[i] = "Could not read data";
	}

	con.name = array[0];
	con.adress = array[1];
	con.email = array[2];
	con.phoneNr = array[3];
	con.date = array[4];
	con.misc = array[5];

	while(is.peek() == '\n') is.ignore();

	return is;
}
