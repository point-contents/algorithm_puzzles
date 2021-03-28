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

std::vector<int> getDigits(int n)
{
    std::vector<int> digits;
    while (n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    std::cout << "Digit Size: " << digits.size() << std::endl;
    std::reverse(digits.begin(), digits.end());
    return digits;
}

static int digPow(int n, int p)
{
    auto digits = getDigits(n);
    long long int sum;
    for (size_t i = 0; i < digits.size(); i++) {
        sum += pow(digits[i], p);
        p++;
    }
    return sum;
}

int main()
{
    std::cout << digPow(695, 2);
    std::cout << digPow(695, 2);
    return 0;
}
