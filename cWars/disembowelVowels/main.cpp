#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <assert.h>


#define LOG(x) std::cout << x << "\n";

template<typename T> void printVec(T vec)
{
	for(auto& things: vec)
	{
		std::cout << things ;
	}
}

std::map<char,bool> vowelMap()
{
	std::map<char,bool> vowelMap = {
		{'a',true},
		{'e',true},
		{'i',true},
		{'o',true},
		{'u',true},
		{'A',true},
		{'E',true},
		{'I',true},
		{'O',true},
		{'U',true}
	};
	
	return vowelMap;
};

std::string disemvowel(std::string str)
{
	auto vMap = vowelMap();
	std::string answer;
	answer.reserve(str.size());

	for(auto i = 0; i < str.size(); i++)
	{
		if(vMap.find(str[i]) != vMap.end())
		{
			continue;
		}
		else
		{
			answer.push_back(str[i]);
		}
	}
	answer.shrink_to_fit();
	return answer;
}

int main()
{
	printVec(disemvowel("asd fa sdfasdi df"));

	return 0;
}
