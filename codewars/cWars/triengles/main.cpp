#include <iostream>
#include <limits>

bool isTriangle(int a, int b, int c)
{
    std::cout << a << "," << b << "," << c << std::endl;

    if (a <= 0 || b <= 0 || c <= 0) {
        return false;
    }
    long long ab, ac, bc;
    ab = a + b;
    ac = a + c;
    bc = b + c;

    if (ab > c && ac > b && bc > a) {
        return true;
    }
    //the A X B is making it overflow? maybe ;
    //	using N = std::numeric_limits<int>::max();

    return false;
}

int main() { return 0; }
