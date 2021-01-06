#include <iostream>
#include <string>

char shiftChar(char c)
{
	int n = (int)c;
	int r = c + 13;
//	if((n > 65 && n < 74) || (n > 96 && n < 106))
	//
	//cases 65 < c < 90 (ie it is lowercase) or 
	// 96 < c < 122 (uppercase)
	
	// end ones 90 == 65 , 122 == 96
	if(std::isalpha(c))
	{
		if((n > 64 && n < 78) || (n > 96 && n < 110))
		{
			return r;
		}
		else
		{
			return r - 26;
		}
	}
	else
	{
		return c;
	}

}

std::string rot13(std::string msg)
{
	std::string chiphered;
	for(auto& chars: msg)
		chiphered.push_back(shiftChar(chars));

  return chiphered;
}

int main()
{
	std::cout << rot13("abcdefghijklmnopqrstuvwxyz") << std::endl;
	return 0;
}
