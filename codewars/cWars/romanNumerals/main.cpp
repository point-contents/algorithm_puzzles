#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << "\n";

template <typename T>
void printVec(T vec)
{
    for (auto& things : vec) {
        std::cout << things << "\n";
    }
}

std::map<int, char> romanSymbols {
    { 1, 'I' },
    { 5, 'V' },
    { 10, 'X' },
    { 50, 'L' },
    { 100, 'C' },
    { 500, 'D' },
    { 1000, 'M' }
};

int findLength(unsigned int value)
{
    int length = 1;
    while (value /= 10) {
        length++;
    }
    return length;
}

std::vector<int> getPlaceValues(int number, int length)
{
    std::vector<int> placeValues;
    for (int i = 0; i < length; i++) {
        int rem = number % 10;
        placeValues.push_back(rem);
        number = number / 10;
    }
    return placeValues;
}

std::string solution(int number)
{
    int nLength = findLength(number);
    auto placeValues = getPlaceValues(number, nLength);
    printVec(placeValues);
    return "yes";
}

int main()
{
    solution(1208342320);

    return 0;
}
