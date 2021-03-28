#include <algorithm>
#include <assert.h>
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

std::map<char, int> countMap()
{
    std::map<char, int> xoMap;
    xoMap['x'];
    xoMap['o'];
    return xoMap;
}

bool checkMapEquality(std::map<char, int> xoMap)
{
    if (xoMap['x'] == xoMap['o']) {
        return true;
    } else {
        return false;
    }
}

bool XO(const std::string& str)
{
    auto freqMap = countMap();
    std::string lowerCase;
    for (auto& chars : str)
        lowerCase.push_back(std::tolower(chars));

    for (size_t i = 0; i < str.size(); i++) {
        if (lowerCase[i] == 'x') {
            freqMap['x']++;
        } else if (lowerCase[i] == 'o') {
            freqMap['o']++;
        } else {
            continue;
        }
    }
    if (checkMapEquality(freqMap)) {
        std::cout << "Even Amount";
    } else {
        LOG("Not Even");
    }
    return checkMapEquality(freqMap);
}

int main()
{
    XO("oxox");

    return 0;
}
