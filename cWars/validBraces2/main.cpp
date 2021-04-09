#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

std::map<char, char> bracePairs()
{
    std::map<char, char> pairs = {
        { '}', '{' },
        { ')', '(' },
        { ']', '[' }
    };

    return pairs;
}

bool validBraces(std::string braces)
{
    std::stack<char> braceStack;
    std::map<char, char> pairs = bracePairs();

    for (size_t i = 0; i < braces.size(); i++) {
        if (braces[i] == '(' || braces[i] == '[' || braces[i] == '{') {
            braceStack.push(braces[i]);
        } else {
            if (braceStack.empty()) {
                return false;
            } else {
                char top = braceStack.top();
                if ((braces[i] == '}' && top == '{')
                    || (braces[i] == ']' && top == '[')
                    || (braces[i] == ')' && top == '(')) {
                    braceStack.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return braceStack.empty();
}

int main()
{
    std::cout << validBraces("()()");

    return 0;
}
