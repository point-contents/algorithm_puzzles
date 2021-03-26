#include <assert.h>
#include <iostream>
#include <regex>
#include <string>

std::string cleanOutput(std::string inputString)
{
    return std::regex_replace(inputString, std::regex("^ +| +$"), "");
}

std::string nextLetter(std::string str)
{
    std::string answer;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            answer.push_back(' ');
        } else {
            int currAsciiValue = (int)str[i];
            if ((currAsciiValue < 90 && currAsciiValue > 64) || (currAsciiValue > 96 && currAsciiValue < 122))
            // end ones 90 == 65 , 122 == 96
            {
                answer.push_back((char)(currAsciiValue + 1));
            } else if (str[i] == 'z') {
                answer.push_back('a');
            } else if (str[i] == 'Z') {
                answer.push_back('A');
            } else {
                answer.push_back(str[i]);
            }
        }
    }
    return answer;
}

int main()
{
    // assert(nextLetter("a") == "b");
    //   std::cout << nextLetter("abc") << std::endl;
    //    std::cout << nextLetter("My Name is Zoo") << std::endl;

    std::cout << "\t\t Should Be: \t\t" << std::endl;
    std::cout << "USF'P2$[A<-DPQ+FB4<%BYSIGL/04.Y%$B$LL!CC" << std::endl;
    std::cout << nextLetter("TRE'O2$[Z<-COP+EA4<%AXRHFK/04.X%$A$KK!BB") << std::endl;

    return 0;
}
