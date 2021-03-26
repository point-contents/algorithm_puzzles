#include <iostream>
#include <vector>

std::vector<int> tribonacci(std::vector<int>& signature, int n)
{
    if (n == 1 || n == 2 || n == 3) {
        return signature;
    }

    std::vector<int> result;

    int sigTotal = 0;
    int vecSize = signature.size();

    for (auto& n : signature)
        sigTotal += n;

    result.push_back(sigTotal);

    else return tribonacci(signature, n - 1);
}

int main()
{
    std::vector<int> theSig = { 0, 0, 1 };
    std::vector<int> theSig2 = { 1, 1, 1 };
    int maximum = 10;

    tribonacci(theSig, maximum);

    return 0;
}
