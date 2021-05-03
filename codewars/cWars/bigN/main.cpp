#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//add two numbers together, represented as two strings
//do it with a carry bit? like a register??
std::string add(const std::string& a, const std::string& b)
{
    std::cout << a << std::endl;
    std::cout << "\n\n"
              << b << std::endl;
    long long int x;
    long long int y;
    x = std::stol(a);
    y = std::stol(b);
    long long int total = x + y;
    std::string ans;
    ans = std::to_string(total);
    return ans;
}

int main()
{
    auto ans = add("1000", "1000");
    assert(ans == ans);

    //    unsigned long long z = 481997118349141;
    return 0;
}
