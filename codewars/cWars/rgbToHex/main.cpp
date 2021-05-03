#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

int validateNumbers(int n)
{
    if (n > 255) {
        return 255;
    } else if (n < 0) {
        return 0;
    } else {
        return n;
    }
}

std::string convertToHex(int r, int g, int b)
{
    char buffer[20];
    sprintf(buffer, "%02X%02X%02X", r, g, b);
    std::string ans = buffer;
    return ans;
}

std::string rgb(int r, int g, int b)
{
    r = validateNumbers(r);
    g = validateNumbers(g);
    b = validateNumbers(b);
    return convertToHex(r, g, b);
}

int main()
{
    std::cout << rgb(-20, 275, 125);

    return 0;
}
