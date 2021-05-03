#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::vector<int> digitize(unsigned long n)
{
    std::vector<int> answer;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        answer.push_back(digit);
    }
    return answer;
}

void printVector(std::vector<int> input)
{
    for (auto& shit : input)
        std::cout << shit << ","
                  << "\n";
}
int main()
{
    int a = 1234;
    auto ans = digitize(a);
    printVector(ans);

    return 0;
}
