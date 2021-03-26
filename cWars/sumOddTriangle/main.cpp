#include <iostream>
#include <vector>

std::vector<int> generateTriangle(int n)
{
    std::vector<int> triangle;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            continue;
        } else {
            triangle.push_back(i);
        }
    }

    return triangle;
}

long long rowSumOddNumbers(unsigned n)
{
    return n;
}
int main()
{

    return 0;
}
