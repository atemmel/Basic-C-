#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>

bool isPalindrome(const std::string & str)
{
	for(int i = 0, j = str.size() - 1; i < str.size() >> 1; i++, j--) if(str[i] != str[j]) return false;
	return true;
}

std::vector<int> randoms(const unsigned int & amount)
{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(0, 99);
	std::vector<int> list;

	for(int i = 0; i < amount; i++) list.push_back(dist(rd));

	return list;
}

int main()
{

	std::string str;
	std::cin >> str;
	isPalindrome(str) ? std::cout << "Ja\n" : std::cout << "Nej\n";

	for(const auto & i : randoms(10)) std::cout << i << std::endl;

	return 0;
}
