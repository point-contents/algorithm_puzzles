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
        std::cout << things.first << ":" << things.second << "\n";
    }
}

bool isOdd(int i)
{
    return ((std::abs(i) % 2) == 1);
}

bool isEven(int i)
{
    return ((std::abs(i) % 2) == 0);
}

int findByType(std::string str, std::vector<int>& arr)
{
    if (str == "Even") {
        auto it = std::find_if(arr.begin(), arr.end(), isEven);
        return *it;
    } else {
        auto it = std::find_if(arr.begin(), arr.end(), isOdd);
        return *it;
    }
}

std::string getUniqueType(std::map<std::string, int> fMap)
{
    if (fMap["Odd"] > 1 && fMap["Even"] == 1) {
        return "Even";
    } else if (fMap["Odd"] == 1 && fMap["Even"] > 1) {
        return "Odd";
    } else {
        return "Not Found";
    }
}

std::map<std::string, int> frequencyMap()
{
    std::map<std::string, int> typeFreq;
    typeFreq.insert(std::pair<std::string, int>("Even", 0));
    typeFreq.insert(std::pair<std::string, int>("Odd", 0));
    return typeFreq;
}

int FindOutlier(std::vector<int> arr)
{
    int result;
    auto oddEvenMap = frequencyMap();

    for (auto& n : arr) {
        if (n % 2 == 0) {
            oddEvenMap["Even"]++;
        } else {
            oddEvenMap["Odd"]++;
        }
    }
    printVec(oddEvenMap);
    auto uniqType = getUniqueType(oddEvenMap);
    result = findByType(uniqType, arr);
    LOG(uniqType);
    LOG("Answer: ");
    LOG(result);

    return result;
}

int main()
{
    std::vector<int> vec = { 2, -6, -10, -3 };
    FindOutlier(vec);
    return 0;
}
