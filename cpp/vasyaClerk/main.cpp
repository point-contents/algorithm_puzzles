#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

std::string tickets(const std::vector<int>& peopleInLine) {
	std::string answer = "YES";
	int ticketPrice = 25;
	int moneyFloat = 0;

	for(auto transactionAmount: peopleInLine)
	{
		if(transactionAmount == ticketPrice)
		{
			moneyFloat += transactionAmount;
		}
		else if(transactionAmount > ticketPrice)
		{
			int difference = transactionAmount - ticketPrice;
			if(difference > moneyFloat)
			{
				answer = "NO";
				break;
			}
			else
			{
				moneyFloat -= difference;
				moneyFloat += transactionAmount;
			}
		}
	}
	
	return answer;
}
	  
int main()
{
//	std::vector<int> arr = {25,50};
//	std::vector<int> arrNO = {25,50,100};
//	std::vector<int> failNo = {25,25,50,50,25,25,25,25,50,100,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,25,25,25,25,50,100,50,25,25,50,100};
//	assert(tickets(arr) == "YES");
//	assert(tickets(arrNO) == "NO");
	std::vector<int> failYes = {25,50,100,25,25,25,25,25,25,100,50,25,50,25,50,25,100,25,50,50,25,50,25,25,50};
	tickets(failYes);
	assert(tickets(failYes) == "NO");
	return 0;
}
