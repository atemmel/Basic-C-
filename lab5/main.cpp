#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

//Adam Temmel
//2017-12-15
//Introduktion till programmering i C++
//Lab 5

int main()
{
	std::ifstream file("hitchhikersguide.txt");	//Öppna filen
	std::map<std::string, int> freq;
	std::vector<std::string> list;
	
	const unsigned int nWords = 50;		//Antalet ord som skall skrivas ut i slutändan

	std::string str;
	while(file >> str) //Så länge det går att plocka ord ur filen
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower); //Förvandla dessa till lowercase (gemener)
		
		std::string filtered;
		for(const auto & c : str) if(isalnum(c)) filtered += c;		//Bygg upp en ny sträng av alla alfanumeriksa bokstäver ur ursprungssträngen
		if(!filtered.empty()) freq[filtered]++;		//Om det finns en sträng kvar, öka dess motsvarande värde i mappen med ett.
	}

	for(int i = 0; i < nWords; i++) //För varje ord som skall skrivas ut, gör följande:
	{

		//Plocka det största elementet ur mappen med hjälp av egenbyggd jämförelsefunktionslambda
		auto s = std::max_element(freq.begin(), freq.end(), [&](const std::pair<std::string, int> & comp1, const std::pair<std::string, int> & comp2)
		{
			//Om värdet redan återfinns i vektorn för de saker som skall skrivas ut, strunda då i det, returnera false
			if(std::find(list.begin(), list.end(), comp1.first) != list.end()) return false;
			if(std::find(list.begin(), list.end(), comp2.first) != list.end()) return false;

			//Annars, evaluera uttrycket som vanligt
			return comp1.second < comp2.second;
		});

		list.push_back(s->first); //Stoppa in maxelementets strängvärde i listan på ord som ska skrivas ut
	}

	std::cout << "De " << nWords << " mest förekommande orden är:" << std::endl;
	for(const auto & s : list) std::cout << s << std::endl;	//Skriv ut samtliga ord i vektorn

	return 0;
}
