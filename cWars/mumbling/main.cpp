#include <ctype.h>
#include <iostream>
#include <map>
#include <string>

std::string accum(const std::string& s)
{
    std::map<char, int> letterLocations;
    std::string answer;

    for (int i = 0; i < s.length(); i++) {
        letterLocations.insert(std::pair<char, int>(s.at(i), i));
    }

    for (auto& letters : letterLocations) {
        answer.push_back(std::toupper(letters.first));

        for (int j = 0; j < letters.second; j++) {
            answer.push_back(letters.first);
        }
        answer.push_back('-');
    }
    return answer;
}

std::string accum2(std::string s)
{
    std::string answer;
    for (int i = 0; i < s.length(); i++) {
        answer.push_back(std::toupper(s.at(i)));
        for (int j = 0; j < i; j++) {
            answer.push_back(std::tolower(s.at(i)));
        }
        answer.push_back('-');
    }
    answer.pop_back();
    return answer;
}

int main()
{
    std::cout << accum2("yes");

    return 0;
}
