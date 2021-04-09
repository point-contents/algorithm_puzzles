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
        std::cout << things.first << " : " << things.second << "\n";
    }
}

std::vector<std::pair<char, int>> makePairVector(std::string s)
{
    std::vector<std::pair<char, int>> answer;
    int counter = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            counter++;
        } else {
            answer.push_back(std::make_pair(s[i], counter + 1));
            counter = 0;
        }
    }
    return answer;
}

int main()
{
    std::string input = "aaaabbbcca";
    auto answer = makePairVector(input);
    printVec(answer);

    return 0;
}
