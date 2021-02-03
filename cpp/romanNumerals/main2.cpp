#include <string>
#include <vector>
#include <iostream>

std::string solution(int number)
{
	std::vector<std::string> romanSym = {"M", "CM", "D", "CD",
		"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	std::vector<int> values = {1000, 900, 500, 400, 100,
		90, 50, 40, 10, 9, 5, 4, 1};

	std::string result = "";

	for (int i = 0; i < 13; ++i)
	{
		while(number - values[i] >= 0)
		{
			result += romanSym[i];
			number -= values[i];
		}
	}
	return result;
}

int main()
{
	auto ans = solution(1875);
	std::cout << ans;

	return 0;
}
