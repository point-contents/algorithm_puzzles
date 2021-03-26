#include <iostream>
#include <stack>
#include <string>

std::string reverseString(std::string str)
{
    std::stack<char> stringStack;
    std::string answer;

    for (auto& letters : str) {
        stringStack.push(letters);
    }
    while (!stringStack.empty()) {
        answer.push_back(stringStack.top());
        stringStack.pop();
    }
    return answer;
}

int main()
{

    return 0;
}
