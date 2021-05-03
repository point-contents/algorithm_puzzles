#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
void printVec(T input)
{
    for (auto things : input) {
        std::cout << things << std::endl;
    }
}

// This seems like a dynamic programming type q
// loop through numbers m to n
// check if its prime
// if it is prime, add it to a map<long long, bool>
//

bool isPrime(int n)
{
    for (int i = 0; i < (n / 2); i++) {
        if (i % n == 0) {
            return 0;
        } else {
            continue;
        }
    }
    return 1;
}

//std::pair<long long, long long> gap(int g, long long m, long long n){};

int main()
{

    return 0;
}
