#include <iostream>
#include <vector>
#include <algorithm>

int findSmallest(std::vector<int> list)
{
	auto it = std::min_element(list.begin(),list.end());
	return *it;

}

int main()
{

	return 0;
}
