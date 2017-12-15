#include <string>
#include <iostream>

std::string toLower(const std::string & str);

struct Contact {
	bool contains(const std::string & term) const;
		
	std::string name;
	std::string adress;
	std::string email;
	std::string phoneNr;
	std::string date;
	std::string misc;
};


std::ostream & operator<<(std::ostream &, const Contact &);
std::istream & operator>>(std::istream &, Contact &);
