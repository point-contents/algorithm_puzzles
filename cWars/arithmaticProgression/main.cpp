#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

void printVector(std::vector<long> inputV)
{
    for (auto& vectorItems : inputV)
        std::cout << vectorItems << ",";
    std::cout << "\n"
              << std::endl;
}

struct seqDetails {
    int m_uniqueSpace;
    int m_uniqueSpaceIndex;
    long m_commonIterator;
};

// takes in a vector of differences
// and returns the most common iterator and
// the value that is out of place

std::pair<long, int> findOddSpace(std::vector<long> elementDifferences)
{
    seqDetails found;

    std::map<long, int> occurancesMap;
//    int uniqueSpace;
//    long commonIterator;
    std::pair<long, int> answerPair;

    for (auto& steps : elementDifferences) {
        int occuranceCount = std::count(elementDifferences.begin(),
            elementDifferences.end(), steps);
        occurancesMap.insert(std::pair<long, int>(steps, occuranceCount));
    }

    for (auto& counts : occurancesMap) {
        if (counts.second < 2) {
            found.m_uniqueSpace = counts.second;
        } else {
            found.m_commonIterator = counts.first;
        }
    }

    auto itr = std::find(elementDifferences.begin(), elementDifferences.end(),
        found.m_uniqueSpace);

    found.m_uniqueSpaceIndex = std::distance(elementDifferences.begin(), itr - 2);

    std::cout << "Element Differences:" << std::endl;
    printVector(elementDifferences);

    std::cout << "Missing Element Index - 1 is: " << found.m_uniqueSpaceIndex
              << std::endl;

    answerPair.first = found.m_commonIterator;
    answerPair.second = found.m_uniqueSpaceIndex;

    return answerPair;
}

int findMissing(std::vector<long> list)
{
    // loop through all of them, and add the difference between
    // it and its preceeding element to a new vector called diffByIndex

    std::cout << "Raw Vector: " << std::endl;
    printVector(list);

    std::vector<long> diffByIndex;

    for (size_t i = 0; i < list.size(); i++) {
        size_t maxSize = list.size() - 1;
        if (i == maxSize) {
            continue;
        } else {
            long piecewiseDifference;
            piecewiseDifference = list[i + 1] - list[i];
            diffByIndex.push_back(piecewiseDifference);
        }
    }

    std::pair<long, int> missingSpotAndIterator = findOddSpace(diffByIndex);

    std::cout << "Pair Contents " << missingSpotAndIterator.first << ":"
              << missingSpotAndIterator.second << std::endl;

    int finalAnswer = list[missingSpotAndIterator.second] + missingSpotAndIterator.first;

    return finalAnswer;
}

int main()
{
    //    std::vector<long> firstInput = {10, 20, 30, 40, 50, 60, 70, 90, 100};
    //    printVector(firstInput);
    //
    //    int first = findMissing(firstInput);
    //    std::cout << "Missing Element is: " << first << std::endl;
    //
    //    std::cout << "\n\n\n";

    std::vector<long> secondInput = { -25, 0, 25, 50, 75, 125, 150, 175 };
    printVector(secondInput);

    findMissing(secondInput);
    int second = findMissing(secondInput);
    std::cout << "Missing Element is: " << second << std::endl;
    return 0;
}
