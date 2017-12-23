#include "filtered_input.h"

bool isValidEmail(const std::string & str)
{
	return 		   str.find('@') != std::string::npos
			&& str.find('.') != std::string::npos
			&& str.find('@') == str.find_last_of('@')
			&& str.find('@') + 1 < str.find('.')
			&& str.back() != '.'
			&& str.front() != '@';
}

void filteredInput(std::string & input, const Filter & filter)
{
	bool valid = 0, failed = 0;
	std::string error;

	switch(filter)
	{
		case ALPHA:
			error = "Input can only contain characters A-Z, a-z or '-'";
			break;
		case NUMERIC:
			error = "Input can only contain numbers";
			break;
		case ALPHANUMERIC:
			error = "Input must only include alphanumeric characters, '.', ',' or spaces";
			break;
		case MAIL:
			error = "Input must be a valid address 'example@mail.domain'";
			break;
		case DATE:
			error = "Input must only contain 8 numbers";
			break;
		case BOOLEAN:
			error = "Input can only be Y(yes) or N(no)";
			break;
		
	}

	while(!valid)
	{
		//Visa felmeddelande om användaren misslyckats med en korrekt inmatning en gång
		if(failed) std::cout << error << std::endl;

		std::getline(std::cin, input);
		std::string tmp;

		switch(filter)
		{
			case ALPHA:
				for(const auto & c : input) if((!ispunct(c) && !isdigit(c)) || c == '-')
					tmp += c;
				break;
			
			case NUMERIC:
				for(const auto & c : input) if(isdigit(c))
					tmp += c;
				break;
			
			case ALPHANUMERIC:
				for(const auto & c : input) if(!ispunct(c) || c == '.' || c == ',' || c == '-' || c == ' ') 
					tmp += c;
				break;

			case DATE:
				if(input.size() == 8)
					for(const auto & c : input) if(isdigit(c))
						tmp += c;
				break;

			case BOOLEAN:
				if(input == "Y" || input == "y")
					tmp = input = "y";
				else if(input == "N" || input == "n")
					tmp = input = "n";
				break;

			case MAIL:
				if(isValidEmail(input))
					tmp = input;
				break;

			default:
				for(const auto & c : input) if(c != '/') tmp += c;
		}

		valid = tmp == input; 	//Valid tilldelas likheten mellan tmp och inmatningen
		failed = 1; 		//Börja mata ut hjälptext
	}
}

void filteredInput(std::string & input, const std::string & ignore)
{
	bool valid = 0, failed = 0;
	std::string error = "Input can not contain the following characters: " + ignore;

	while(!valid)
	{
		//Visa felmeddelande om användaren misslyckats med en korrekt inmatning en gång
		if(failed) std::cout << error << std::endl;

		std::getline(std::cin, input);
		std::string tmp;

		for(const auto & c : input) if(ignore.find(c) == -1)
			tmp += c;

		valid = tmp == input; 	//Valid tilldelas likheten mellan tmp och inmatningen
		failed = 1; 		//Börja mata ut hjälptext
	}
}
