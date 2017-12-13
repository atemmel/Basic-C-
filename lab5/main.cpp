#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <chrono>

int main()
{
	std::ifstream file("hitchhikersguide.txt");
	std::map<std::string, int> freq;
	std::vector<std::string> list;
	
	const unsigned int nWords = 50;

	std::string str;
	while(file >> str) 
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		
		std::string filtered;
		for(const auto & c : str) if(isalnum(c)) filtered += c;
		if(!filtered.empty()) freq[filtered]++;
	}

	for(int i = 0; i < nWords; i++)
	{

		auto s = std::max_element(freq.begin(), freq.end(), [&](const std::pair<std::string, int> & comp1, const std::pair<std::string, int> & comp2)
		{
			if(std::find(list.begin(), list.end(), comp1.first) != list.end()) return false;
			if(std::find(list.begin(), list.end(), comp2.first) != list.end()) return false;
			return comp1.second < comp2.second;
		});

		list.push_back(s->first);
	}

	std::cout << "De " << nWords << " mest förekommande orden är:" << std::endl;
	for(const auto & s : list) std::cout << s << std::endl;

	return 0;
}
