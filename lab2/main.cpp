#include <iostream>
#include <vector>

int main()
{
	std::vector<int> values;

	int tmp;
	while(std::cin)
	{
		std::cin >> tmp;
		values.push_back(tmp);
	}
	
	if(!values.empty())
	{

		values.pop_back();

		int sum = 0, min = values[0], max = values[0];

		for(const auto & v : values)
		{
			sum += v;
			if(v > max) max = v;
			if(v < min) min = v;
		}

		float med = static_cast<float>(sum) / static_cast<float>(values.size());

		std::cout << "Medelvärde: " << med << std::endl;
		std::cout << "Max: " << max << std::endl;
		std::cout << "Min: " << min << std::endl;
	}

	return 0;
}
