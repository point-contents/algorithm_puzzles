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

int nextYear(int p0, double percent, int aug)
{
    return (p0 + (p0 * percent) + aug);
}

class Arge {
public:
    static int nbYear(int p0, double percent, int aug, int p)
    {
        int total = p0;
        int years = 0;
        percent = percent / 100;
        while (total < p) {
            int nextYearTotal = nextYear(total, percent, aug);
            int difference = nextYearTotal - total;
            total += difference;
            years++;
        }
        return years;
    }
};

int main()
{
    Arge aggregate;
    std::cout << aggregate.nbYear(1500, 5, 100, 5000);
    std::cout << aggregate.nbYear(1500000, 2.5, 10000, 2000000);
    return 0;
}
