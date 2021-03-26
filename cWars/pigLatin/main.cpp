#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <map>

#define LOG(x) std::cout << x << "\n";

template <typename T>
void printVec(T vec)
{
    for (auto& things : vec) {
        std::cout << things << "\n";
    }
}

std::vector<std::string> tokenizeString(const std::string& inputString,
    char delimiter)
{

    std::vector<std::string> result;
    std::stringstream ss(inputString);
    std::string item;

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

std::string swapFirstLetter(std::string s)
{
    std::string answer;
    answer.reserve(s.size());

    if (std::isalnum(s[0])) {
        for (int i = 1; i < s.size(); i++) {
            answer.push_back(s[i]);
        }
        answer.push_back(s[0]);
        answer.append("ay");
        return answer;
    } else {
        return s;
    }
}

std::string pig_it(std::string str)
{
    std::vector<std::string> tokens = tokenizeString(str, ' ');
    std::vector<std::string> mutatedTokens;
    mutatedTokens.reserve(tokens.size());
    std::string answer;

    for (auto& words : tokens) {
        mutatedTokens.emplace_back(swapFirstLetter(words));
    }

    for (auto& outputTokens : mutatedTokens)
        answer.append(outputTokens + " ");
    answer.pop_back();

    return answer;
}

int main()
{
    auto input = "O tempora o mores !";

    std::cout << input << "\n";
    auto answewr = pig_it(input);
    std::cout << answewr << "\n";
    std::cout << "Oay emporatay oay oresmay !";

    return 0;
}
