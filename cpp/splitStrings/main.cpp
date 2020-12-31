#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> solution(const std::string &s)
{
	std::vector<std::string> answer; 
	std::string inputCopy = s; 

	inputCopy.erase(std::remove(inputCopy.begin(), inputCopy.end(), ' '),inputCopy.end());

	std::cout << inputCopy << std::endl;
	std::cout << "Size: " << inputCopy.size() << std::endl;
	std::cout << "Odd or Even: " << (inputCopy.size() % 2) << std::endl;

	bool oddIndicator;
	if(inputCopy.size()	% 2 == 0) 
	{
		oddIndicator = false;
	}
	else
	{
		oddIndicator = true;
	}

	for(auto it = inputCopy.begin(); it != inputCopy.end(); it++) 
	{
		{
		std::string stringPair;

			if(*it == ' ')
			{
				continue;
			}
			else
			{
				stringPair.push_back(*it);
				stringPair.push_back(*(it + 1));
			}

		answer.push_back(stringPair);
		}
	}

	if(oddIndicator)
	{
		answer.push_back("_");
	}

    return answer; // Your code here
}

void testGarbage(std::string inputString)
{
	auto ans =  solution(inputString);

	for(auto shit: ans)
		std::cout << shit << " ";


	std::cout << "\n" << std::endl;

		
}


int main()
{
	std::string a = "here are some words";
	std::string b = "Here are some other words";

	testGarbage(a);
	testGarbage(b);

	return 0;
}
