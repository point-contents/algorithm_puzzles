#include "assert.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// Task:
//
// For each number in strng calculate its "weight" and then find two numbers of strng that have:
//
//     the smallest difference of weights ie that are the closest
//     with the smallest weights
//     and with the smallest indices (or ranks, numbered from 0) in strng
//
// Output:
//
//     an array of two arrays, each subarray in the following format:
//
// [number-weight, index in strng of the corresponding number, original corresponding number in strng]

// split the string of numbers into individual numbers
// get the weight for each number, put it into a tuple <string, index, weight>

//helper functions
template <typename T>
void printVec(T input)
{
    for (auto things : input) {
        std::cout << things << std::endl;
    }
}

//struct is probably more appropriate
class numberCharacteristics {
    std::string s;
    int n;
    long long calculatedStringWeight;

public:
    numberCharacteristics(std::string inputString, int translatedString,
        long long stringWeight)
    {
        s = inputString;
        n = translatedString;
        calculatedStringWeight = stringWeight;
    }
    std::string getOriginal()
    {
        return s;
    }
    int getValue()
    {
        return n;
    }
    long long getWeight()
    {
        return calculatedStringWeight;
    }
};

std::vector<std::string> splitIt(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
//std::tuple<std::string, unsigned int, long long
//is what we want in the end: a tuple of the string,
//its index and its weight
int weightIt(std::string s)
{
    long long stringAsNumber = std::stoll(s);
    long long tmp;
    long long sum = 0;
    while (stringAsNumber > 0) {
        tmp = stringAsNumber % 10;
        sum += tmp;
        stringAsNumber /= 10;
    }
    return sum;
}

std::vector<numberCharacteristics> collateIt(std::string s)
{
    std::vector<numberCharacteristics> collated;
    std::vector<std::string> splitString = splitIt(s, ' ');
    for (size_t i = 0; i < splitString.size(); i++) {
        int weight = weightIt(splitString[i]);
        numberCharacteristics record = numberCharacteristics(splitString[i], i, weight);
        collated.push_back(record);
    }
    return collated;
}

std::vector<std::string> closest(const std::string& strng)
{
    std::vector<std::string> splitString = splitIt(strng, ' ');
    return splitString;
}

int main()
{
    std::string a = "100 25 33 77";
    std::vector<std::string> b = closest(a);
    for (auto& words : b) {
        std::cout << weightIt(words) << std::endl;
    }
    printVec(b);

    return 0;
}
