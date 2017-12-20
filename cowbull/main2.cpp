#include <vector>
#include <array>
#include <map>
#include <random>
#include <algorithm>
#include <iostream>

#define OUTPUTLESS

const unsigned int codeLength = 4;
const auto seed = std::random_device()();

typedef std::array<unsigned, codeLength> Code;
typedef std::pair<unsigned, unsigned> Result;

unsigned getRandom(const unsigned & max)
{
	static std::mt19937 mt(seed);	
	std::uniform_int_distribution<int> dist(0, max);
	return dist(mt);
}

std::vector<Code> getAllSolutions()
{
	std::vector<Code> solutions;
	for(unsigned i = 0; i < 10; i++)
		for(unsigned j = 0; j < 10; j++)
			for(unsigned k = 0; k < 10; k++)
				for(unsigned l = 0; l < 10; l++)
				{
					if(i != j && i != k &&
							i != l &&
							j != k &&
							j != l &&
							k != l)
							solutions.push_back({i,j,k,l});
				}

	return solutions;
}

bool validGuess(const Code & guess, const std::map<Code, Result> & guesses, 
		const std::vector<Code> & solutions)
{
	for(int i = 0; i < guess.size(); i++)
		for(int j = 0; j < guess.size(); j++)
			if(i != j && guess[i] == guess[j]) return false;

	return guesses.find(guess) == guesses.end() && std::find(solutions.begin(), solutions.end(), guess) != solutions.end();
}

Result getResult(const Code & guess, const Code & answer)
{
	Result result;

	for(int i = 0; i < guess.size(); i++)
		if(guess[i] == answer[i]) result.first++;

	for(int i = 0; i < guess.size(); i++)
	{
		auto it = std::find(answer.begin(),answer.end(),guess[i]);
		if(it != answer.end() && it - answer.begin() != i)
			result.second++;
	}

	return result;
}

Code generateCode(const std::map<Code,Result> & guesses)
{ 
	static auto solutions = getAllSolutions();
	Code guess;

	do
	{
		std::vector<Code> bulls, cows, bad;
		for(const auto & g : guesses)
		{
			if(g.second.first > 0)
				bulls.push_back(g.first);
			if(g.second.second > 0)
				cows.push_back(g.first);

			if(g.second.first  == 0 && g.second.second == 0)
				bad.push_back(g.first);
		}
		
		/*		std::remove_if(solutions.begin(), solutions.end(), [&](Code & c)
		{
			for(const auto & b : bad)
			{
				for(int i = 0; i < b.size(); i++)
					for(int j = 0; j < b.size(); j++)
						if(b[i] == c[j])
							return true;
			}
			return false;
		});*/

		if(guesses.empty()) 	guess = {1,2,3,4};
		else if(std::find(solutions.begin(), solutions.end(), Code{5,6,7,8}) != solutions.end()) 	guess = {5,6,7,8};
		else if(std::find(solutions.begin(), solutions.end(), Code{1,2,7,8}) != solutions.end())	guess = {1,2,7,8};
		else guess = solutions[getRandom(solutions.size())];

//		int s = solutions.size();
		for(int i = 0; i < bad.size(); i++)
		{
			for(int j = 0; j < solutions.size(); j++)
			{
				auto r = getResult(solutions[j],bad[i]);
				if(r.second > 0 || r.first > 0)
					solutions.erase(solutions.begin() + j);
			}
		}
		for(auto & g : guesses)
		{
			for(int j = 0; j < solutions.size(); j++)
			{
				if(solutions[j] == g.first)
					solutions.erase(solutions.begin() + j);
			}
		}
		for(auto & c : cows)
		//	if(guesses[c].second + guesses[c].first == 4)
			for(auto & g : guesses)
				if(g.first == c)
					if(g.second.first + g.second.second == 4)
					{
						//first e bull
						//second e cows
					//	std::cout << "he e fyra " << std::endl;	
						for(int j = 0; j < solutions.size(); j++)
						{
							auto r = getResult(solutions[j],c);
							if(r.second + r.first != 4)
								solutions.erase(solutions.begin() + j);
						}
					}


			//if(s > solutions.size())
			//std::cout << "Solutions decreased by: " << s - solutions.size() << std::endl;

	
	}
	while(!validGuess(guess, guesses, solutions));

	//std::cout << "solutions: " << solutions.size() << std::endl;

	return guess;
}

int main()
{
	std::map<Code, Result> guesses;
	Code correctAnswer, currentAnswer;
	unsigned n_guesses = 0;

#ifndef OUTPUTLESS
	std::cout << "Mata in rätt svar: ";
	for(auto & i : correctAnswer) std::cin >> i;
#else
	auto solutions = getAllSolutions();
	correctAnswer = solutions[getRandom(solutions.size())];
#endif

	while(currentAnswer != correctAnswer)
	{
		currentAnswer = generateCode(guesses);
#ifndef OUTPUTLESS	
		for(const auto & i : currentAnswer) std::cout << i;
		
		std::cout << std::endl;
#endif

		auto result = getResult(currentAnswer, correctAnswer);

#ifndef OUTPUTLESS
		std::cout << "Bulls: " << result.first << " Cows: " << result.second << '\n';
#endif	

		//std::cin.get();
		guesses[currentAnswer] = result;
		++n_guesses;
	}

#ifndef OUTPUTLESS
	std::cout << "Det gicks bra" << std::endl;

	std::cout << n_guesses << " / " << getAllSolutions().size() << " gissningar utförda" << std::endl;
#else
	std::cout << n_guesses << ' ';
#endif

	return 0;
}
