#include <iostream>
#include <vector>
#include <string>
#include <assert.h>


void printVector(std::vector<int> inputVector)
{
  std::cout << "Input Vector: ";
  for(auto shit: inputVector)  
    std::cout << shit << ",";
  std::cout << "\n";
}


std::string tickets(const std::vector<int>& peopleInLine) {
    std::cout << "\n\n --NEW----NEW--\n\n";
    std::string answer = "YES";
    int ticketPrice = 25;
    int moneyFloat = 0;
    printVector(peopleInLine);
    for(auto transactionAmount: peopleInLine)
    {
        std::cout << "\n ""\t---BEGIN--TRANSACTION---\t:" << std::endl;
        std::cout << "\nTransaction Amount: " << transactionAmount << std::endl;
        std::cout << "Float Balance:" << moneyFloat << std::endl;
      
        if(transactionAmount == ticketPrice)
        {
            moneyFloat += transactionAmount;
            std::cout << "\nAdding:" << transactionAmount << " (amt == price) "<< std::endl;
            std::cout << "\n"<< "\t---END--TRANSACTION---\t:" << std::endl;
        }
        else if(transactionAmount > ticketPrice)
        {
            int difference = transactionAmount - ticketPrice;
            if(difference > moneyFloat)
            {
              std::cout << "\n\n --EXIT----EXIT--";
              std::cout << "\n\n --EXIT----EXIT--\n\n\n";
                answer = "NO";
                break;
            }
            else if(difference == moneyFloat || difference < moneyFloat)
            {
                std::cout << "Subtracting: " << difference << std::endl;
                moneyFloat -= difference;
				moneyFloat += ticketPrice;
                std::cout << "\n\n" << "\t---END--TRANSACTION---\t\n\n" << std::endl;
            }
        }
    }
    std::cout << "Final Answer: " << answer << std::endl; 
    std::cout << "\n\n --FINISH----FINISH--\n\n";
    return answer;
}

	  
int main()
{
	std::vector<int> arr = {25,50};
	assert(tickets(arr) == "YES");

//	std::vector<int> arrNO = {25,50,100};
//	std::vector<int> failNo = {25,25,50,50,25,25,25,25,50,100,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,25,25,25,25,50,100,50,25,25,50,100};
//
//	assert(tickets(arrNO) == "NO");
//
//	std::vector<int> failYes = {25,50,100,25,25,25,25,25,25,100,50,25,50,25,50,25,100,25,50,50,25,50,25,25,50};
//	assert(tickets(failYes) == "NO");

	
	std::vector<int> expectedNo = {25,25,50,50,50,25,50,25,25};
	std::cout << tickets(expectedNo);
	return 0;
}
