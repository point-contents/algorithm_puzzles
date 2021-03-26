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

using namespace std;

void printEgyptian(int nr, int dr)
{
    if (dr == 0 || nr == 0)
        return;

    // If numerator divides denominator, then simple division
    // makes the fraction in 1/n form
    if (dr % nr == 0) {
        cout << "1/" << dr / nr;
        return;
    }

    // If denominator divides numerator, then the given number
    // is not fraction
    if (nr % dr == 0) {
        cout << nr / dr;
        return;
    }

    // If numerator is more than denominator
    if (nr > dr) {
        cout << nr / dr << " + ";
        printEgyptian(nr % dr, dr);
        return;
    }

    // We reach here dr > nr and dr%nr is non-zero
    // Find ceiling of dr/nr and print it as first
    // fraction
    int n = dr / nr + 1;
    cout << "1/" << n << " + ";

    // Recur for remaining part
    printEgyptian(nr * n - dr, dr * n);
}

int main(int argc, char* argv[])
{
    printEgyptian(100, 25023498);
    return 0;
}
