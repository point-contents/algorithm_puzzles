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
        std::cout << things.first << "\n";
        std::cout << things.second << "\n";
    }
}

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target)
{
    std::pair<std::size_t, std::size_t> answer;
    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = 1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == target && i != j) {
                answer.first = i;
                answer.second = j;
            }
        }
    }
    return answer;
}

int main(int argc, char* argv[])
{
    auto arr = { 25, 75, 100 };
    auto ans = two_sum(arr, 100);
    std::cout << ans.first << ans.second;
    return 0;
}
