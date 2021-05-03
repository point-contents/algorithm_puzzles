#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

float calcAverage(std::vector<int> classPoints)
{
    int total = 0;
    int size = 0;
    float answer = 0;
    for (auto& it : classPoints) {
        total += it;
        size++;
    }
    answer = (total / size);
    return answer;
}

bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{

    float average = calcAverage(classPoints);
    if (yourPoints < average) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    std::vector<int> myClass = { 3, 4, 5 };
    assert(betterThanAverage(myClass, 1) == false);
    assert(betterThanAverage(myClass, 9) == true);

    return 0;
}
