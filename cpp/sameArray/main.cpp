#include <iostream>
#include <set>
#include <vector>

class Same {

   public:
    bool comp(std::vector<int>& a, std::vector<int>& b) {

    std::vector<int> m_Squared;
    std::set<int> setOfSquares;
    int m_InitialSetSize;
    int m_SubsequentSetSize;

	if (a.size() && b.size() == 0) {
	    return false;
	}
	for (auto& unsquared : a) m_Squared.push_back(unsquared * unsquared);
	for (auto& squared : m_Squared) setOfSquares.insert(squared);
	m_InitialSetSize = setOfSquares.size();
	for (auto& testElements : b) setOfSquares.insert(testElements);
	m_SubsequentSetSize = setOfSquares.size();

	if (m_SubsequentSetSize == m_InitialSetSize) {
		std::cout << "They are the same" << std::endl;
	    return true;
	} else {
		std::cout << "They are not the same" << std::endl;
	    return false;
	}
    }
};

int main() {
    std::vector<int> smallA = {1, 2, 3, 4, 5};
    std::vector<int> smallB = {1, 4, 9, 16, 25};
    std::vector<int> smallC = {1, 4, 7, 16, 25};

	Same test;

	test.comp(smallA, smallB);

	Same test2;

	test2.comp(smallA, smallC);


    return 0;
}
