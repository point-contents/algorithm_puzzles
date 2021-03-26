#include <algorithm>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << "\n";

bool containsFive(int number)
{
    while (number != 0) {
        int curr_digit = number % 10;
        if (curr_digit == 5 || curr_digit == -5)
            return true;
        number /= 10;
    }

    return false;
}

int dontGiveMeFive(int start, int end)
{
    int count = 0;
    for (int i = start; i < (end + 1); i++) {
        if (containsFive(i)) {
            continue;
        } else {
            count++;
        }
    }
    return count;
}

int main()
{
    assert(dontGiveMeFive(1, 9) == 8);
    assert(dontGiveMeFive(4, 17) == 12);
    assert(dontGiveMeFive(4, 17) == 12);

    return 0;
}
