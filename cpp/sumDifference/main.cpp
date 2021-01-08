#include <iostream>
#include <vector>

int sumOfDifferences(const std::vector<int>& arr){
  int answer = 0;
  if(arr.size() == 0 || arr.size() == 1)
  {
    return answer;
  }
  else
  {
    for(int i = arr.size() - 1; i > 0; i--)
    {
	  int current = arr[i];	 
	  int next = arr[i - 1];	 
	  int difference = current - next;
      answer += difference;
    }
    return answer;
  }
}

int main()
{
	std::vector<int> v = {1,2,24,20,7,12,4,9,28,15,17,30,28,18,9,27,19};
	std::cout << sumOfDifferences(v) << std::endl;

	return 0;
}
