#include <string>
#include <iostream>

struct Contact {
	bool contains(const std::string & term) const;
	
	
	std::string name;
	std::string adress;
	std::string email;
	std::string phoneNr;
	std::string date;
	std::string misc;

protected:
	const char delimeter = '/';
};


std::ostream & operator<<(std::ostream &, const Contact &);
std::istream & operator>>(std::istream &, Contact &);
