#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <assert.h>

bool is_isogram(std::string str) {
	std::set<char> charSet;
	for(auto& chars: str)
	{
		charSet.insert(std::tolower(chars));
	}
	if(charSet.size() == str.size())
	{
		return true;
	}
	else
		return false;

}

int main()
{
	assert(is_isogram("aba") == false);
	assert(is_isogram("ab") == true);
	assert(is_isogram("abC") == true);
	assert(is_isogram("abCa") == false);
	std::cout << is_isogram("yeshojsdf") << "Yes\n";

	return 0;
}
