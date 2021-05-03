#include <iostream>
#include <map>
#include <stack>

std::map<char, char> validPairs()
{
    std::map<char, char> bracketFriends;
    bracketFriends.insert(std::pair<char, char>('}', '{'));
    bracketFriends.insert(std::pair<char, char>(']', '['));
    bracketFriends.insert(std::pair<char, char>(')', '('));

    return bracketFriends;
}

bool compareToTop(std::stack<char> theStack, char theComparison)
{
    bool answer;

    auto bracePairs = validPairs();
    auto it = bracePairs.find(theComparison);

    if (it != bracePairs.end()) {
        if (theStack.top() == it->second) {
            answer = true;
        } else {
            answer = false;
        }
    } else {
        answer = false;
    }

    return answer;
}

bool valid_braces(std::string braces)
{
    std::stack<char> bracesStack;
    bool isValid;

    for (size_t i = 0; i < braces.length(); i++) {
        switch (braces[i]) {
        case '(':
            bracesStack.push('(');
            break;
        case '{':
            bracesStack.push('{');
            break;
        case '[':
            bracesStack.push('[');
            break;
        case ')':
            isValid = compareToTop(bracesStack, ')');
            break;
        case ']':
            isValid = compareToTop(bracesStack, ']');
            break;
        case '}':
            isValid = compareToTop(bracesStack, '}');
            break;
        }
    }
    return isValid;
}

int main()
{
    valid_braces("()");
    valid_braces("(())");
    valid_braces("[(]");
    valid_braces("[(])");

    return 0;
}
