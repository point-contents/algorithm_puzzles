#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

class Same {
public:
    static bool comp(std::vector<int>& a, std::vector<int>& b)
    {
        static std::vector<long> m_Squared;
        static std::set<long> setOfSquares;
        static int m_InitialSetSize;
        static int m_SubsequentSetSize;

        if (a.size() && b.size() == 0) {
            return false;
        }

        if (a.empty() || b.empty()) {
            return false;
        }
        for (auto& unsquared : a)
            m_Squared.push_back(unsquared * unsquared);
        for (auto& squared : m_Squared)
            setOfSquares.insert(squared);
        m_InitialSetSize = setOfSquares.size();
        for (auto& testElements : b)
            setOfSquares.insert(testElements);
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

int main()
{
    std::vector<int> smallA = { 1, 2, 3, 4, 5 };
    std::vector<int> smallB = { 1, 4, 9, 16, 25 };
    std::vector<int> smallC = { 1, 4, 7, 16, 25 };

    std::vector<int> aa = { 121, 144, 19, 161, 19, 144, 19, 11 };
    std::vector<int> bb = { 14641, 20736, 361, 25921, 361, 20736, 362, 121 };

    Same::comp(smallA, smallB);
    Same::comp(smallA, smallC);
    Same::comp(aa, bb);

    std::vector<int> randA;
    std::vector<int> randB;

    for (int m = 0; m < 1000; m++) {
        randA.push_back(std::rand());
    }

    for (auto& things : randA)
        randB.push_back(things * things);

    Same::comp(randA, randB);

    std::vector<int> randC = { -147, 472, -42, 409, 58, 318, 381,
        472, 376, 400, 51, 242, 334, 121 };

    std::vector<int> randD = { 338, 1764, 2601, 3364, 14641,
        21609, 58564, 101124, 111556, 141376,
        145161, 160000, 167281, 222784 };

    Same::comp(randC, randD);

    std::cout << randC.size() << " A Size" << std::endl;
    std::cout << randD.size() << " B Size" << std::endl;

    std::cout << "\nRaw " << std::endl;

    for (auto& thing : randC)
        std::cout << thing << std::endl;

    std::cout << "\n Squared " << std::endl;

    for (auto& thingy : randC) {
        std::vector<int> squaredOne;
        squaredOne.push_back(thingy * thingy);
        std::sort(squaredOne.begin(), squaredOne.end());
    }

    std::cout << "\n Comparison " << std::endl;

    for (auto& thingo : randD)
        std::cout << thingo << " , ";
    return 0;
}
