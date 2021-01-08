#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <assert.h>

int solution(int number) 
{
  int ans = 0;
  for(int i = 0; i < number; i++)
  {
    if((i % 3 == 0)) != (i % 5 == 0))
    {
      ans += 0;
    }
	else
		continue;
  }
  std::cout << "Input: " << number << std::endl;
  std::cout << "Answer: " << ans << std::endl;
  return ans;
}

int main()
{
	solution(1020);
	return 0;
}
