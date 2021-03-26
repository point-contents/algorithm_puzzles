#include <iostream>
#include <math.h>

bool isPrime(int num)
{
    if (num < 2 || num % 2 == 0) {
        std::cout << "no ";
        return false;
    }

    if (num == 2) {
        std::cout << "no ";
        return true;
    }

    int maximum = std::floor(sqrt(num));
    for (int i = 3; i <= maximum + 1; i++) {
        if (num % i == 0) {
            std::cout << "no ";
            return false;
        }
    }
    std::cout << "no ";
    return true;
}

int main()
{
    int input;
    std::cin >> input;
    isPrime(input);
    return 0;
}
