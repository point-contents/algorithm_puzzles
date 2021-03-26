#include <iostream>
#include <set>
#include <string>

std::string duplicate_encoder(std::string word)
{
    std::string duplicateLetters;
    for (std::string::size_type i = 0; i < word.size(); i++) {
        for (std::string::size_type j = 0; j < word.size(); j++) {
            if (word[j] == word[i]) {
                int counter = 0;
                duplicateLetters[counter] = word[i];
                counter++;
            }
        }
    }
    return duplicateLetters;
}

int main()
{
    std::cout << "Type a word: " << std::endl;
    std::string input;
    std::cin >> input;
    std::string answer;
    answer = duplicate_encoder(input);
    std::cout << answer;

    return 0;
}
