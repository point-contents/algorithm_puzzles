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
        std::cout << things;
    }
    std::cout << "\n";
}

std::vector<char> uniqueInOrder(const std::string& iterable)
{
    std::vector<char> answer;
    for (int i = 0; i < iterable.size(); i++) {
        if (iterable[i] == iterable[i + 1]) {
            continue;
        } else {
            answer.push_back(iterable[i]);
        }
    }
    return answer;
}

int main()
{
    std::string input1 = "AAAABBBCCDAABBB";
    std::string input2 = "ABBCcAD";
    printVec(uniqueInOrder(input1));
    printVec(uniqueInOrder(input2));
    return 0;
}
