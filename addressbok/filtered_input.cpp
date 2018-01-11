/*
Adam Temmel
2018-01-11
Introduktion till programmering i C++
Examinerande lab: Adressbok
*/

#include "filtered_input.h"

bool isValidEmail(const std::string & str)
{
	return 		   str.find('@') != std::string::npos //Kolla om @ finns
			&& str.find('.') != std::string::npos //Kolla om . finns
			&& str.find('@') == str.find_last_of('@') //Kolla om bara ett @ finns
			&& str.find('@') + 1 < str.find('.') //Kolla om @ finns före .
			&& str.back() != '.' //Kolla om . inte är det sista elementet
			&& str.front() != '@'; //Kolla om @ inte är det första elementet
}

void filteredInput(std::string & input, const Filter & filter)
{
	bool valid = 0, failed = 0;
	std::string error;

	switch(filter)	//Gå igenom vilket filter som ska användas och bygg upp strängen därefter
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

	while(!valid) //Så länge den senaste inmatningen inte ansågs godtycklig
	{
		//Visa felmeddelande om användaren misslyckats med en korrekt inmatning en gång
		if(failed) std::cout << error << std::endl;

		std::getline(std::cin, input);
		std::string tmp;

		switch(filter)
		{
			case ALPHA: //Släpp bara igenom bokstäver och -
				for(const auto & c : input) if((!ispunct(c) && !isdigit(c) && !isspace(c)) || c == '-')
					tmp += c;
				break;
			
			case NUMERIC: //Släpp bara igenom siffror
				for(const auto & c : input) if(isdigit(c))
					tmp += c;
				break;
			
			case ALPHANUMERIC: //Släpp bara igenom siffror, bokstäver, och ett fåtal tecken
				for(const auto & c : input) if(!ispunct(c) || c == '.' || c == ',' || c == '-' || c == ' ') 
					tmp += c;
				break;

			case DATE: //Släpp bara igenom giltiga datum
				if(input.size() == 8)
					for(const auto & c : input) if(isdigit(c))
						tmp += c;
				break;

			case BOOLEAN: //Släpp bara igenom yes eller no
				if(input == "Y" || input == "y")
					tmp = input = "y";
				else if(input == "N" || input == "n")
					tmp = input = "n";
				break;

			case MAIL: //Släpp bara igenom giltiga epostadresser
				if(isValidEmail(input))
					tmp = input;
				break;
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
