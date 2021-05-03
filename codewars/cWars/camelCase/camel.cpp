#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string to_camel_case(string s)
{

    int total = s.length();

    bool indicator;

    if (isupper(s[0])) {
        indicator = true;
    } else
        indicator = false;

    for (int i = 0; i < total; i++) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        } else
            continue;
    }

    string lowered = s;

    for (int i = 0; i < total; i++) {
        if (lowered[i] == ' ') {
            lowered[i + 1] = toupper(lowered[i + 1]);
            continue;
        } else
            lowered[i] = lowered[i];
    }

    lowered.erase(std::remove(lowered.begin(), lowered.end(), ' '), lowered.end());

    if (indicator == true) {
        lowered[0] = toupper(lowered[0]);
    }

    return lowered;
}

int main()
{
    string value;
    getline(std::cin, value);
    string answer = to_camel_case(value);
    cout << answer << endl;
    return 0;
}
