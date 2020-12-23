#include <vector>

vector<long long> pascalsTriangle(int n)
{
	std::vector<std::vector<long long>> arr[n][n];

	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
		{
			if(j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
			else
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	return arr;


  //your code here
}

int main()
{
	pascalsTriangle(1);

	return 0;
}
