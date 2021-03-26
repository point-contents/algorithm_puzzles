#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

std::string createPhoneNumber(const int arr[10])
{

    int toParenthize[3];

    for (int i = 0; i < 3; i++) {
        toParenthize[i] = arr[i];
    }

    LOG("First 3");

    for (int parens : toParenthize) {
        std::cout << parens << std::endl;
    }

    int firstGroup[3];

    for (int j = 3; j < 6; j++) {
        firstGroup[j - 3] = arr[j];
    }

    LOG("First Non Bracket");

    for (int firsts : firstGroup) {
        std::cout << firsts << std::endl;
    }

    int secondGroup[4];
    for (int k = 6; k < 10; k++) {
        secondGroup[k - 6] = arr[k];
    }

    LOG("Final Group");
    for (int seconds : secondGroup) {
        std::cout << seconds << std::endl;
    }

    std::string finalAnswer;

    finalAnswer.append("(");

    for (int l = 0; l < 3; l++) {
        finalAnswer.append(std::to_string(toParenthize[l]));
    }

    finalAnswer.append(") ");

    for (int m = 0; m < 3; m++) {
        finalAnswer.append(std::to_string(firstGroup[m]));
    }

    finalAnswer.append("-");

    for (int n = 0; n < 4; n++) {
        finalAnswer.append(std::to_string(secondGroup[n]));
    }

    return finalAnswer;
}

int main()
{
    int inputArray[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

    std::cout << "1234567890 array " << std::endl;
    std::cout << createPhoneNumber(inputArray) << std::endl;

    return 0;

    // => returns "(123) 456-7890" ;
}
