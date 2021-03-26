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

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int solve(std::vector<std::string> v){
	int oddCount = 0;
	int evenCount = 0;
	std::vector<int> vecOfNums;

	for(int i = 0; i < v.size(); i++)
	{
		if(is_number(v[i]))
		{
			vecOfNums.push_back(std::stoi(v[i]));
		}
		else
		{
			continue;
		}
	}

	for(int j = 0; j < vecOfNums.size(); j++)
	{
		if(vecOfNums[j] % 2 == 0)
		{
			evenCount++;
		}
		else
		{
			oddCount++;
		}
	}
					
	return evenCount - oddCount;
}

int main()
{
	std::vector<std::string> input = {"a","7","3","1","2","4","a4"};
	auto answer = solve(input);
	std::cout << answer;
	return 0;
}
