#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
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

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls)
{
    std::vector<unsigned long long> ans;
    ans.reserve(ls.size());
    auto sum = std::accumulate(ls.begin(), ls.end(), 0);
    ans.emplace_back(sum);
    for (int i = 0; i < ls.size(); i++) {
        sum -= ls[i];
        ans.emplace_back(sum);
    }
    return ans;
}

int main()
{
    std::vector<unsigned long long> a = { 20, 20, 19, 16, 10, 0 };
    auto b = partsSum(a);
    printVec(b);

    return 0;
}
