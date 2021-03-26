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

#include <string>
#include <vector>

class SequenceSum {
    int count = 0;
    std::string sequence;

public:
    SequenceSum(int);
    std::string showSequence();
};

std::string SequenceSum::showSequence()
{
    std::string answer;
    for (int i = 0; i < sequence.size(); i++) {
        answer.push_back(sequence[i]);
        if (i + 1 == sequence.size()) {
            break;
        } else {
            answer.push_back('+');
        }
    }
    answer += " = ";
    answer += std::to_string(count);
    return answer;
}

SequenceSum::SequenceSum(int c)
{
    for (int i = 0; i <= c; i++) {
        sequence += std::to_string(i);
        count += i;
    }
}

int main()
{
    SequenceSum summy(6);
    std::cout << summy.showSequence();
    return 0;
}
