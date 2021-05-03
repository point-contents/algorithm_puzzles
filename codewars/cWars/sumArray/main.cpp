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

int arrayPlusArray(std::vector<int> a, std::vector<int> b)
{
    return std::accumulate(a.begin(), a.end(), 0)
        + std::accumulate(b.begin(), b.end(), 0);
}

int main(int argc, char* argv[])
{

    return 0;
}
