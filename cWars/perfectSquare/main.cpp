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

bool checkIfPerfect(long int& sq)
{
    auto sqrt = std::pow(sq, 0.5);
    return std::floor(sqrt) == sqrt;
}

long int calcNext(long int& sq)
{
    auto sqrt = std::pow(sq, 0.5);
    return std::pow((sqrt + 1), 2);
}

long int findNextSquare(long int sq)
{
    if (checkIfPerfect(sq)) {
        return calcNext(sq);
    } else {
        return -1;
    }
}

int main()
{
    assert(findNextSquare(121) == 144);
    assert(findNextSquare(114) == -1);
    return 0;
}
