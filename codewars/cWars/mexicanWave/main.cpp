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

std::vector<std::string> wave(std::string y)
{
    std::vector<std::string> answer;
    for (size_t i = 0; i < y.size(); i++) {
        if (y[i] == ' ') {
            continue;
        } else {
            std::string personUp = y;
            personUp[i] = std::toupper(personUp[i]);
            answer.push_back(personUp);
        }
    }
    return answer;
}

int main()
{
    auto ans = wave("hello");
    printVec(ans);
    return 0;
}
