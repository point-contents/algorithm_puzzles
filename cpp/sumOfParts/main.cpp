#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <assert.h>


#define LOG(x) std::cout << x << "\n";

template<typename T> void printVec(T vec)
{
	for(auto& things: vec)
	{
		std::cout << things << "\n";
	}
}

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
  std::vector<unsigned long long> ans;
  ans.reserve(ls.size());
  for(int i = 0; i < ls.size(); i++)
  {
    auto sum = std::accumulate(ls.begin() + i, ls.end(), 0);
    ans.push_back(sum);
  }
  return ans;
}

int main()
{
  std::vector<unsigned long long> a = {20,20,19,16,10,0};
  auto b = partsSum(a);
  printVec(b);

	return 0;
}
