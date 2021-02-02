#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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
  for(long i = 0; i < ls.size(); i++)
  {
    unsigned long long tmp = 0;
    for(long j = i; j < ls.size(); j++)
    {
      tmp += ls[j];
    }
    ans.push_back(tmp);
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
