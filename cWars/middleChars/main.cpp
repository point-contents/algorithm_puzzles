#include <iostream>
#include <string>
#include <cmath>

#define LOG(x) std::cout << x << std::endl;

std::string get_middle(std::string input) 
{
	std::string answer;
	int length = input.length();
	bool oddIndicator;
	(length % 2 == 0) ? oddIndicator = false : oddIndicator = true;
	
	if(oddIndicator)
	{
		answer.push_back(input.at(std::ceil(length/2)));
	}
	else
	{
		int charIndex = std::floor(length/2);
		answer.push_back(input.at(charIndex - 1));
		answer.push_back(input.at(charIndex));
	}
	return answer;
}
int main()
{
	std::cout << "FUCK: " << get_middle("FUCK") << std::endl;
	std::cout << "FUCKE: " << get_middle("FUCKE") << std::endl;
	return 0;
}
