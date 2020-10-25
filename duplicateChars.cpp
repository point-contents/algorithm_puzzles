#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>

void duplicates(std::string word)
{

	//make lowercase
	
	std::transform(word.begin(), word.end(), word.begin(),
			[](unsigned char c){return std::tolower(c); });

	//make a set for both the characters and the duplicates.
	//sets cannot have duplicates, so there will only be one of each

	std::set<char> characters;
	std::set<char> duplicates;

	for(std::string::size_type i = 0; i < word.size(); i++)
	{
		char c = word[i];

		if(!std::isspace(static_cast<int>(c)))
		{
			if(characters.count(c) == 0)
			{
				characters.insert(c);
			}
			else
			{
				duplicates.insert(c);
			}
		}
	}

	std::cout << "Repeated: " << "\n";
	for(std::set<char>::const_iterator it = duplicates.begin(); it != duplicates.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << "\n" << "Unique Characters" << "\n";
	for(std::set<char>::const_iterator it = characters.begin(); it != characters.end(); it++)
	{
		std::cout << *it << " ";
	}
}

int main()
{
	std::string input = "Hello There is notmuch that we can do here ";
	duplicates(input);

	return 0;
}
