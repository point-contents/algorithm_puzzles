#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string& s)
{
    std::vector<std::string> answer;
    std::string inputCopy = s;

    // didnt need this apparently
    //inputCopy.erase(std::remove(inputCopy.begin(), inputCopy.end(), ' '),inputCopy.end());

    std::cout << inputCopy << std::endl;
    std::cout << "Size: " << inputCopy.size() << std::endl;
    std::cout << "Odd or Even: " << (inputCopy.size() % 2) << std::endl;

    bool oddIndicator;
    (inputCopy.size() % 2 == 0) ? oddIndicator = false : oddIndicator = true;

    for (int i = 0; i < inputCopy.size(); i = i + 2) {
        {
            std::string stringPair;

            {
                if (i == 0 || i % 2 == 0) {
                    stringPair.push_back(inputCopy.at(i));
                    if (i + 1 == inputCopy.size() && oddIndicator) {
                        stringPair.push_back('_');
                    } else if (i + 1 < inputCopy.size()) {
                        stringPair.push_back(inputCopy.at(i + 1));
                    } else {
                        continue;
                    }
                } else {
                    continue;
                }
            }

            answer.push_back(stringPair);
        }
    }

    return answer;
}

void testGarbage(std::string inputString)
{
    auto ans = solution(inputString);

    for (auto shit : ans)
        std::cout << shit << " ";

    std::cout << "\n"
              << std::endl;
}

int main()
{
    std::string a = "here are some words";
    std::string b = "Here are some other words";

    testGarbage(a);
    testGarbage(b);

    return 0;
}
