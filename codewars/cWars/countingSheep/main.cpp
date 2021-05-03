#include <iostream>
#include <string>
#include <vector>

int count_sheep(std::vector<bool> arr)
{
    int counter = 0;
    for (auto sheep : arr) {
        if (sheep == true) {
            counter++;
        } else {
            continue;
        }
    }
    return counter;
}

int main()
{

    return 0;
}
