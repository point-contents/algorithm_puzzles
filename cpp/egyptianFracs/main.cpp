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

class Decomp
{
  double numer, denom;
  float total;
  std::vector<int> denomVec = {};
public:
  void calcTotal(const std::string &nrStr, const std::string &drStr)
  {
	numer = std::stod(nrStr);
	denom = std::stod(drStr);
	total = numer / denom;
  }

  void printTotal() { LOG(total) };

  std::string decompose(const std::string &nrStr, const std::string &drStr)
  {
	calcTotal(nrStr, drStr);


	return "";
  }
};

int main(int argc, char* argv[])
{
	Decomp calc;
	calc.decompose("10", "100");
	calc.printTotal();
	return 0;
}
