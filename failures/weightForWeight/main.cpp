#include <iostream>
#include <sstream>
#include <istream>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <assert.h>
#include <boost/lexical_cast.hpp>



#define LOG(x) std::cout << x << "\n";

template<typename T> void printVec(T vec)
{
	for(auto& things: vec)
	{
		std::cout << things << "\n";
	}
}

template<typename T> void printMap(T mappy)
{
	for(auto& things: mappy)
	{
		std::cout << things.first << " : "; 
		std::cout << things.second << "\n";
	}
}

std::vector<std::string> tokenizeS(std::string s)
{
	std::istringstream iss(s);
	std::vector<std::string> tokens;

	std::copy(std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			std::back_inserter(tokens));
	return tokens;	
}

std::vector<int> makeTokenNumeric(std::vector<std::string> tokenCollection)
{
	std::vector<int> numericToken;
	numericToken.reserve(tokenCollection.size());
	for(int i = 0; i < tokenCollection.size(); i++)
	{
		numericToken.push_back(boost::lexical_cast<int>(
				tokenCollection[i]));
	}
	return numericToken;
	
}

std::vector<int> makeNumericTokensFromString(std::string strng)
{
	std::vector<std::string> tokens = tokenizeS(strng);
	std::vector<int> numericTokens = makeTokenNumeric(tokens);
	return numericTokens;
}

int addNumbersIndividually(int n)
{
	int sum = 0;
	while(n != 0)
	{
		sum = sum + (n % 10);
		n = n / 10;
	}
	return sum;	
}

std::vector<int> getTokenWeight(std::vector<int>& tokenCollection)
{
	std::vector<int> tokenSizes;

	for(int i = 0; i < tokenCollection.size(); i++)
	{
		tokenSizes.push_back(addNumbersIndividually(tokenCollection[i]));	
	}
	return tokenSizes;
}

std::map<int,int> weightMap(const std::string& strng)
{
	std::map<int, int> mappy;
	std::vector<int> numericTokens = makeNumericTokensFromString(strng);
	printVec(numericTokens);
	std::vector<int> sizes = getTokenWeight(numericTokens);
	std::cout << "\n";
	printVec(sizes);
	for(int i = 0; i < numericTokens.size(); i++)
	{
		mappy[sizes[i]] = numericTokens[i];
	}
	return mappy;
}

std::vector<int> sortWeights(std::vector<int> numericTokens)
{
	sort(numericTokens.begin(), numericTokens.end());
	return numericTokens;
}

std::string generateSortedString(std::vector<int> sortedNumericTokens, 
		std::map<int,int> weightMap)
{
	std::string answer;
	for(int i = 0; i < sortedNumericTokens.size(); i++)
	{
		auto item = weightMap.find(sortedNumericTokens[i]);
		answer.push_back(item->second);
	}
	return answer;
}


class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng);
};

std::string WeightSort::orderWeight(const std::string &strng)
{
	auto tokenWeightMap = weightMap(strng);
	auto sortedTokens = sortWeights(makeNumericTokensFromString(strng));
	std::string ans = generateSortedString(sortedTokens, tokenWeightMap);
	std::cout << "This should not be empty" <<  ans;
	return ans; 
}


int main()
{
	WeightSort w;
	std::string inputS = "310390 39497 166137 131971 25135 344343 56885 342421 261461 383115 55206 136253 480341 258173 130198 237767 247670 143457 34121 340953";
	std::cout << w.orderWeight(inputS);


	return 0;
}
