#include <bitset>
#include <iostream>
#include <string>

unsigned int countBits(unsigned long long n)
{
    std::bitset<64> myBitset = std::bitset<64>(n);

    return myBitset.count();
}

int main()
{
    std::cout << "150" << std::endl;
    std::cout << countBits(150) << std::endl;

    std::cout << "1000" << std::endl;
    std::cout << countBits(1000) << std::endl;
    return 0;
}
