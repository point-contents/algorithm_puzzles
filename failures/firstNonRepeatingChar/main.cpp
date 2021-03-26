#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void printVec(std::vector<char> v)
{
    for (auto& things : v) {
        std::cout << things << "\n";
    }
}

void printMap(std::map<char, int> m)
{
    for (auto& things : m) {
        std::cout << things.first << things.second << "\n";
    }
}

char findFirstDuplicate(std::string s, std::vector<char> v)
{
    for (auto& letter : s) {
        if (std::find(v.begin(), v.end(), letter)) {
            return letter;
        } else {
            continue;
        }
    }
    return '_';
}

std::vector<char> getDuplicatedChars(std::map<char, int> m)
{
    std::vector<char> duplicates;
    for (auto& freqs : m) {
        if (freqs.second > 1) {
            duplicates.push_back(freqs.first);
        } else {
            continue;
        }
    }
    return duplicates;
}

std::map<char, int> countFrequencies(std::string s)
{
    std::map<char, int> freq;
    for (auto& letter : s) {
        if (freq.find(letter) == freq.end()) {
            freq.insert(std::pair<char, int>(letter, 1));
        } else {
            freq[letter]++;
        }
    }
    return freq;
}

int main()
{
    std::string str = "yes";
    std::map<char, int> charFrequencies = countFrequencies(str);
    printMap(charFrequencies);
    std::vector<char> dupes = getDuplicatedChars(charFrequencies);
    printVec(dupes);
    findFirstDuplicate(str, dupes);
    return 0;
}
