#include <string>
#include <iostream>
#include <vector>
#include <set>

class WhichAreIn
{
	public:
	  static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
	  {
		  std::set<std::string> matches;
		  std::vector<std::string> matchesVector;

		  for(auto subToSearch: array1)
		  {
			for(auto stringToSearch: array2)
			{
				if(stringToSearch.find(subToSearch) != std::string::npos)
				{
					matches.insert(subToSearch);
				}
			}
		  }
		  for(auto matchedSub: matches)
		  {
			  matchesVector.push_back(matchedSub);
		  }

		  return matchesVector;
	 }

};

int main()
{

	WhichAreIn testSearch;

	std::vector<std::string> a1, a2, t1;

	std::cout << "\n\nFirst Test: " << std::endl;

	a1 = {"arp", "live", "strong"};

	a2 = {"tarp", "mice", "bull", "ard"};

	t1 = {"lively", "alive", "hard", "sharp", "armstrong"};


	std::vector<std::string> answer1 =  testSearch.inArray(a1,t1);

	for(auto vectorAnswers: answer1)
	{
		std::cout << vectorAnswers << std::endl;
	}

	std::cout << "\n\nSecond Test: " << std::endl;

	std::vector<std::string> answer2 = testSearch.inArray(a2,t1);

	for(auto vectorAnswers2: answer2)
	{
		std::cout << vectorAnswers2 << std::endl;
	}

	return 0;
}
