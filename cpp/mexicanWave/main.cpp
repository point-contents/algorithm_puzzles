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
		std::cout << things << "\n";
	}
}

std::vector<std::string> wave(std::string y){
	std::vector<std::string> answer;
	int counter = 0;
	for(int i = 0; i < y.size(); i++)
	{
		if(y[i] == ' ')
		{
			continue;
		}
		else
		{
			std::string personUp = y;
			personUp[i] = std::toupper(personUp[i]);
			answer.push_back(personUp);
		}
	}
	return answer;
}

int main()
{
	auto ans = wave("hello");
	printVec(ans);
	return 0;
}
