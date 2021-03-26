#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>

static std::vector<std::string> concatenateArray(std::vector<std::string>& strarr, int k)
{
	std::vector<std::string> concatArray;
	for(size_t j = 0; j < strarr.size(); j++)
	{
		std::string answer; 
		for(int i = 0; i < k; i++)
		{
			if(j+i < strarr.size())
			{
				answer += strarr[j+i];
			}
			else
			{
				continue;
			}
		}
		concatArray.push_back(answer);
	}
	return concatArray;
}

std::string getBiggest(std::vector<std::string>& strarr)
{
	auto it = std::max_element(strarr.begin(), strarr.end(),
			[](const std::string& a, const std::string& b){
			return a.length() < b.length();
			});
	return *it;
}

static std::string longestConsec(std::vector<std::string> &strarr, int k)
{
	auto concatArr = concatenateArray(strarr, k);
	std::string answer = getBiggest(concatArr);
	return answer;
}

int main()
{
	  std::vector<std::string> arr = {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
	  std::cout << longestConsec(arr, 2) << std::endl; //==  "abigailtheta";
	  std::vector<std::string> arr2 = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
	  std::cout << longestConsec(arr2, 1);// == "oocccffuucccjjjkkkjyyyeehh";
    
	return 0;
}
