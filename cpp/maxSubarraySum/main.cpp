#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

// Got this explanation of the algorithm from https://web.stanford.edu/class/cs161/Sections/Section1/section1-sols.pdf
// But I cant figure out how to make it for c++ yet.

//If length is one, we return the array if the element is positive,
//and otherwise return [ ].

//Next, divide the array in two,L and R, and recurse on each half to find the 
//max-sum subarray of Land the max-sum subarray of R. Call these maxLeft and maxRight

//The best subarray of the third type will be the concatenation best subarray 
//that ends at the midpoint and the best subarray that starts at the midpoint.  
//Call this maxAcross.

//Once we have these three subarray candidates, we return the max-sum subarray 
//among these three types as our final answer.

int maxSequence(const std::vector<int>& arr){
	int answer;
	std::vector<int> left;	
	std::vector<int> right;	
	int maxLeft;
	int maxRight;
	int count = 0;


	for(auto& numbers: arr)
		count += numbers;

	if(arr.size() == 0)
	{
		answer = 0;
	}
	else if(arr.size() == 1)
	{
		answer = *arr.begin();
	}
	else
	{
		for(int i = 0; i < ((int)arr.size() / 2); i++)
		{
			left.push_back(arr[i]);
		}
		for(int j = (arr.size() / 2) ; j < arr.size() ; j++)
		{
			right.push_back(arr[j]);
		}
		maxLeft = maxSequence(left);
		maxRight = maxSequence(right);
	}

	std::vector<int> subArrayTotals = {count,maxLeft,maxRight};
	answer = *std::max_element(subArrayTotals.begin(),subArrayTotals.end());

	return answer;
}

int main()
{
	std::vector<int> a;
	std::vector<int> b = {1};
	std::vector<int> c = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	//assert(maxSequence(a) == 0);
	//assert(maxSequence(b) == 1);
	std::cout << maxSequence(c);
	return 0;
}
