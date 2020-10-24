#include <math.h>
#include <iostream>

bool isPrime(int num)
{
	if(num < 2 || num % 2 == 0)
	{
		return false;
	}

	if(num == 2)
	{
		return true;
	}

	int maximum = std::floor(sqrt(num));
	for(int i = 3; i <= maximum + 1; i++)
	{
		if(num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::cout << "Check for prime" << std::endl;
	std::cout << "Enter a number" << std::endl;
	int input;
	std::cin >> input;
	if(isPrime(input))
	{
		std::cout << "ITS A PRIME ";
	}
	else
	{
		std::cout << "NAH";
	}
	return 0;
}
