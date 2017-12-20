#include <iostream>
#include <vector>

//Adam Temmel
//2017-12-15
//Introduktion till programmering i C++
//Lab 2

int main()
{
	std::vector<int> values;

	int tmp;
	while(std::cin)	//Så länge användaren matar in godtyckliga värden
	{
		std::cin >> tmp; //Stoppa dessa i tmp
		values.push_back(tmp);	//Och stoppa därefter tmp i vektorn
	}
	
	if(!values.empty())	//Under förutsättningen att det finns värden i vektorn
	{

		values.pop_back(); //Klipp det sista elementet (Med andra ord, det första felande värdet alternativt eof)

		int sum = 0, min = values[0], max = values[0];	//Initiera ett par värden

		for(const auto & v : values)	//För varje element i vektorn
		{
			sum += v;		//Öka summan med vektorns värde
			if(v > max) max = v;	//Om värdet är större än det hittils största värdet, skriv då över
			if(v < min) min = v;	//Om värdet är mindre än det hittils minsta värdet, skriv då över
		}

		float med = static_cast<float>(sum) / static_cast<float>(values.size());	//Casta allt till floats och beräkna medelvärdet

		//Skriv ut samtliga resultat
		std::cout << "Antalet värden: " << values.size() << std::endl;
		std::cout << "Medelvärde: " << med << std::endl;
		std::cout << "Max: " << max << std::endl;
		std::cout << "Min: " << min << std::endl;
	}

	return 0;
}
