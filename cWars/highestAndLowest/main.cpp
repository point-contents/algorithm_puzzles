#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
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

std::vector<int> parseString(const std::string& s, char delim)
{
    std::vector<int> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(std::stoi(item));
    }

    return result;
}

std::string highAndLow(const std::string& numbers)
{
    std::string answer;
    auto vec = parseString(numbers, ' ');
    auto itMax = std::to_string(*(std::max_element(vec.begin(), vec.end())));
    auto itMin = std::to_string(*(std::min_element(vec.begin(), vec.end())));
    answer = itMax + " " + itMin;
    return answer;
}

int main()
{
    std::cout << highAndLow("10 2 -2 -10");
    return 0;
}
