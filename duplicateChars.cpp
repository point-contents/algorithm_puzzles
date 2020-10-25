#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>
#include <assert.h>
#include <vector>

std::string lowerIt(std::string& upper)
{
	//make string lowercase
	std::string word = upper;
	
	std::transform(word.begin(), word.end(), word.begin(),
			[](unsigned char c){return std::tolower(c); });
	
	return word;
}

std::vector<char> leftJoin(std::set<char>& characters, std::set<char>& duplicates)
{

	//make a set of ones that are not duplicated,
	//these ones will be replaced by "(" in the final string

	std::vector<char> notDuplicated;

	std::set_difference(characters.begin(), characters.end(),
						duplicates.begin(), duplicates.end(),
						std::inserter(notDuplicated, notDuplicated.begin()));	

	return notDuplicated;
}

std::string duplicates(std::string& word)
{

	word = lowerIt(word);

	//make a set for both the characters and the duplicates.
	//sets cannot have duplicates, so there will only be one of each

	std::set<char> characters;
	std::set<char> duplicates;
	std::vector<char> notDuplicated;

	//loop throught the string, do not understand what the 
	//static cast is doing here exactly.
	
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

	notDuplicated = leftJoin(characters, duplicates);

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
	return word;
}

int main()
{
	std::string input; 
	std::cout << "\n" << "Add input, duplicate values will be ')'" << "\n";
	std::getline(std::cin, input);
	std::cout << duplicates(input);

	return 0;
}
