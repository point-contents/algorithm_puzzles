#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>
#include <assert.h>
#include <vector>


void duplicates(std::string& word)
{

	std::cout << "Input = " << word << "\n";
	//
	//make lowercase
	
	std::transform(word.begin(), word.end(), word.begin(),
			[](unsigned char c){return std::tolower(c); });

	//make a set for both the characters and the duplicates.
	//sets cannot have duplicates, so there will only be one of each

	std::set<char> characters;
	std::set<char> duplicates;
	std::vector<char> notDuplicated;

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

	std::set_difference(characters.begin(), characters.end(),
						duplicates.begin(), duplicates.end(),
						std::inserter(notDuplicated, notDuplicated.begin()));	


	if(characters.size() > duplicates.size())
	{
		assert(notDuplicated.size() >= 0);
	}
	else
	{
		assert(notDuplicated.size() == 0);
	}

	for(std::string::size_type i = 0; i < word.size(); i++)
	{

		for(std::set<char>::const_iterator it = duplicates.begin(); it != duplicates.end(); it++)
		{
			if(*it == word[i])
			{
				char moreThanOnce = ')';
				word[i] = moreThanOnce ; 
				assert(word[i]=')');
			}
		}
	}

	// Need to work out how to do the same thing for characters
	// that arent in the duplicated set 
	
	for(std::string::size_type i = 0; i < word.size(); i++)
	{
		for(std::vector<char>::const_iterator it = notDuplicated.begin();
				it != notDuplicated.end(); it++)
		{
			if(*it == word[i])
			{
				char once = '(';
				word[i] = once;
				assert(word[i] = '(');
			}
		}
	}

	std::cout << "Answer = ?? " << "\n";
	std::cout << word << "\n";


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

	std::cout << "\n" << "Non Duplicated: " << "\n";
	
	for(int i = 0; i < notDuplicated.size(); i++)
	{
		std::cout << notDuplicated[i] << ", ";
	}
	//loop through non duplicated array
}

int main()
{
	std::string input; 
	std::cout << "\n" << "Add input, duplicate values will be ')'" << "\n";
	std::getline(std::cin, input);
	duplicates(input);

	return 0;
}
