#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <assert.h>


#define LOG(x) std::cout << x << "\n";

template<typename T> void printVec(T vec)
{
	for(auto& things: vec)
	{
		std::cout << things << "\n";
	}
}

std::vector<std::string> getPurmutations(std::string& s)
{
	std::vector<std::string> p;
	std::set<std::string> sP;

	do {
		sP.insert(s);
		LOG(s);
	} while (std::next_permutation(s.begin() ,s.end()));

	for(auto ps: sP) { p.push_back(ps); };

	std::cout << "Length of: " << sP.size();

	return p;
}

int main(int argc, char* argv[])
{
	std::string input = "bcad";
	getPurmutations(input);
	return 0;
}
