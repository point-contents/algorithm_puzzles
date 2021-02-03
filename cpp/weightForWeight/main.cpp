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

int addNumbersIndividually(int n)
{
	return n;	
}

std::vector<int> countTokSize(std::vector<std::string>& tokenCollection)
{
	std::vector<int> tokenSizes;

	for(int i = 0; i < tokenCollection.size(); i++)
	{
		tokenSizes.push_back(std::accumulate(tokenCollection[i].begin(),
					tokenCollection[i].end(),0));	
	}
	return tokenSizes;
}

std::map<int,int> weightMap(const std::string& strng)
{
	std::map<int, int> mappy;
	std::vector<std::string> tokens = tokenizeS(strng);
	std::vector<int> numericTokens = makeTokenNumeric(tokens);
	std::vector<int> sizes = countTokSize(tokens);

	for(int i = 0; i < tokens.size(); i++)
	{
		mappy[numericTokens[i]] = sizes[i];
	}
	return mappy;
}


class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng);
};

std::string WeightSort::orderWeight(const std::string &strng)
{
	auto tokenWeightMap = weightMap(strng);
	printMap(tokenWeightMap);
	return "yes"; 
}


int main()
{
	WeightSort w;
	std::string inputS = "310390 39497 166137 131971 25135 344343 56885 342421 261461 383115 55206 136253 480341 258173 130198 237767 247670 143457 34121 340953";
	w.orderWeight(inputS);

	return 0;
}
