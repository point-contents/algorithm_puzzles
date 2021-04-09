#include <algorithm>
#include <assert.h>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << "\n";

template <typename T>
void printVec(T vec)
{
    for (auto& things : vec) {
        std::cout << things;
    }
    std::cout << "\n";
}

std::string encrypt(std::string text, int n)
{
    if (n < 0) {
        return text;
    } else {
        std::string subAnswer = text;
        for (int i = 0; i < n; i++) {
            std::string secondLetters;
            std::string firstLetters;
            for (size_t i = 1; i < subAnswer.size(); i += 2) {
                secondLetters.push_back(subAnswer[i]);
            }
            for (size_t j = 0; j < text.size(); j += 2) {
                firstLetters.push_back(subAnswer[j]);
            }
            subAnswer = secondLetters + firstLetters;
        }
        return subAnswer;
    }
}

std::vector<std::string> splitIntoTwo(std::string s)
{
    std::vector<std::string> leftAndRight;
    //this is left
    leftAndRight.push_back(s.substr(0, s.length() / 2));
    //this is right
    leftAndRight.push_back(s.substr(s.length() / 2));

    return leftAndRight;
}

std::string recurseDecryp(std::string s)
{
    if (s.length() < 1) {
        return s;
    } else {
        std::vector<std::string> splitString = splitIntoTwo(s);
        printVec(splitString);
        std::string answer;
        std::string processedString;

        for (size_t i = 0; i < splitString[1].size(); i++) {
            processedString.push_back(splitString[1][i]);
            processedString.push_back(splitString[0][i]);
            answer = processedString;
        }
        return recurseDecryp(answer);
    }
}

std::string decryptOnce(std::string encryptedText)
{
    std::string subAnswer = encryptedText;
    std::string processedString;
    std::vector<std::string> splitString = splitIntoTwo(subAnswer);

    for (size_t i = 0; i < splitString[1].size(); i++) {
        processedString.push_back(splitString[1][i]);
        processedString.push_back(splitString[0][i]);
        subAnswer = processedString;
    }
    return subAnswer;
}

std::string decryptN(std::string s, int n)
{
    std::string answer = s;
    for (int i = 0; i < n; i++) {
        answer = decryptOnce(answer);
        printVec(answer);
    }
    return answer;
}

int main()
{
    std::cout << "This is a test! "
              << "\n";
    std::cout << "Encrypt once"
              << "\n";
    std::cout << encrypt("This is a test!", 2) << "\n";
    std::cout << "Decrypt once"
              << "\n";
    std::cout << decryptOnce("hsi  etTi sats!") << "\n";
    std::cout << "Decrypt N amounts"
              << "\n";
    std::cout << decryptN("s eT ashi tist!", 2) << "\n";

    return 0;
}
