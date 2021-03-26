#include <iostream>
#include <string>

char shiftChar(char c, int amt)
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

std::string rot13(std::string msg)
{
    std::string chiphered;
    for (auto& chars : msg)
        chiphered.push_back(shiftChar(chars, 1));

    return chiphered;
}

int main()
{
    std::cout << rot13("Aabcdefghijklmnopqrstuvwxyz") << std::endl;
    return 0;
}
