#include <iostream>
#include <map>
#include <vector>

//use a map
//loop through array, if we find the value
//from the array in the map, then increment the
//keys value this will give us the frequency of each
//one

std::map<int,int> getFrequencies(std::vector<int> inputArray)
{
	std::map<int,int> frequencies;
	for(auto& number: inputArray)
	{
		frequencies[number]++;
	}

	return frequencies;
}

void printMap(std::map<int,int> inputMap)
{
	for(auto& shit: inputMap)
		std::cout << shit.first << "," << shit.second << std::endl;

}

int findOdd(const std::vector<int>& numbers){
	std::map<int,int> numberFrequencies = getFrequencies(numbers);
	printMap(numberFrequencies);
	int answer;
	std::pair<int,int> answerPair;

	for(auto& things: numberFrequencies)
	{
		std::cout << "Value: " << things.first << " Frequency: " << things.second << std::endl;

		if((things.second) % 2 == 0)
		{
			continue;
		}
		else
		{
			answerPair = things;
			answer = things.first;
		}
	}
	std::cout << "\t\t" << answerPair.first << "," << answerPair.second << std::endl;

	return answer;
}

int main()
{
	std::vector<int> a = {1,7,7,5,5,5,5,1,8};
	std::cout << findOdd(a) << std::endl;

	return 0;
}
