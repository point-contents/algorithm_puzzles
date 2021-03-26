#include <cmath>
#include <iostream>
#include <string>
#include <vector>

//			First Variation on Caesar Cipher
//
//this one is hard, there are a few different things going on
//the shift isnt too hard to understand, each time you go up,
//the shift increases.

// But what I dont understand is how to split them up better/properly

char shiftChar(char c, int amt = 1)
{
    int s = c + amt;
    if (std::isalpha(c)) {
        if (std::islower(c)) {
            return (((s - 'a') % 26) + 'a');
        } else {
            return (((s - 'A') % 26) + 'A');
        }
    } else {
        return c;
    }
}

std::vector<std::string> splitString(std::string inputString)
{
    std::vector<std::string> outputVector;
    int len = inputString.size();

    int equalSizes = std::floor((inputString.length() / 4));
    int remainder = inputString.size() - equalSizes;
    int equalChunkTotal = inputString.size() - remainder;

    outputVector.push_back(inputString.substr(0, equalSizes));
    outputVector.push_back(inputString.substr((equalSizes), equalSizes));
    outputVector.push_back(inputString.substr((equalSizes * 2), equalSizes));
    outputVector.push_back(inputString.substr((equalSizes * 3), equalSizes));
    outputVector.push_back(inputString.substr((equalSizes * 4), remainder));

    return outputVector;
}

std::vector<std::string> movingShift(const std::string& s)
{
    std::string subAnswer;
    std::vector<std::string> messages;
    //need to split the string into 5 different strings;
    std::cout << "Input Length: " << s.length() << std::endl;

    for (int i = 0; i < s.size(); i++) {
        char s_C = shiftChar(s[i], i + 1);
        subAnswer.push_back(s_C);
    }
    messages.push_back(subAnswer);

    auto answer = splitString(subAnswer);
    return answer;
}

int main()
{
    std::vector<std::string> answer = movingShift("I should have known that you would have a perfect answer for me!!!");
    //should equal bdfh km I think
    for (auto shit : answer)
        std::cout << shit << ",";

    return 0;
}
