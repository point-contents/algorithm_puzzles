#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> myChars(const std::string& word)
{
	std::set<char> mySet;
	for(std::string::size_type i = 0; i < word.size(); i++)
	{
		for(std::string::size_type j = 1; j < i; j++)
		{
			if(word[j] == word[i])
			{
				if(mySet.find(word[i]) == mySet.end())
				{
					mySet.insert(word[i]);
				}
			}
		}
	}
	std::vector<std::string> answer;

	std::set<char>::iterator it = mySet.begin();
	while(it != mySet.end())
	{
		answer.push_back(*it);
		it++;
	}

}


int main()
{
	std::string input = "Shitty";
	myChars(input);

	return 0;
}
