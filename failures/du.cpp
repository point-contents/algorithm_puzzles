#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> duplicates(std::string word)
{
	std::vector <std::string> dupes;
	for(std::string::size_type i = 0; i < word.size(); i++)
	{
		for(std::string::size_type j = 0; j < word.size(); j++)
		{
			if(word[j] == word[i])
			{
				int counter = 0;
				dupes.push_back(word[j]);
				counter++;
			}
		}
	}
	return dupes;
}
int main()
{
	std::vector<std::string> result;
	std::string input;		
	std::cin >> input;
	
	result = duplicates(input);

	for(std::vector<std::string>::const_iterator i = result.cbegin; i != result.cend(); i++)
	{
		std::cout << result[i] << std::endl;
	}
	
	return 0;
}
