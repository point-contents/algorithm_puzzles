#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <assert.h>

std::vector<float> generateN(int n)
{
	std::vector<float> oVec;
	for(int i = 0; i < n; i++)
	{
		float calc = (((((n + i)/3) * 7) - 1300) % 2938) * i;
		oVec.push_back(calc);
	}

	return oVec;
}

void printV(std::vector<float> iVec)
{
	for(auto& items: iVec)
		std::cout << items << ",";
	std::cout << "\n\n\n" << iVec.size();
}


int main()
{
	int n;
	std::cin >> n; 
	auto thing = generateN(n);
	printV(thing);
	

	return 0;
}
