#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<int> createDigitArray(int number)
{
    std::vector<int> outputArray;
    for (int i = 0; i < number; i++) {
        outputArray.push_back(number % 10);
        number = number / 10;
    }
    return outputArray;
}

void printArray(std::vector<int> vec)
{
    for (auto& numbers : vec)
        std::cout << numbers;
    std::cout << "\n";
}

std::string autoMorphic(int number)
{
    std::string answer = "answer";
    int nSquared = number * number;
    std::vector<int> digitVec = createDigitArray(number);
    std::vector<int> squaredDigits = createDigitArray(nSquared);
    std::vector<int> comparisonVec;

    for (size_t i; i < digitVec.size(); i++) {
        comparisonVec.push_back(digitVec[i]);
    }
    printArray(digitVec);
    printArray(squaredDigits);
    printArray(comparisonVec);

    return answer;
}

int main()
{
    autoMorphic(15);

    return 0;
}
