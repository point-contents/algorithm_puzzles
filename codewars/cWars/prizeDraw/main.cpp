#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> tokenizeString(std::string s)
{
    std::vector<std::string> tokenizedVector;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokenizedVector.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokenizedVector.push_back(s);
    return tokenizedVector;
}

int calculateNameTotal(std::string s, int weight)
{
    int subTotal = s.length();
    int total = 0;
    for (auto& letters : s) {
        int value;
        value = (int)((std::tolower(letters)) - 65);
        subTotal += value;
        total = subTotal * weight;
    }

    return total;
}

bool sortPairByValue(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
    return (a.second < b.second);
}

std::string nthRank(const std::string& st, std::vector<int>& we, int n)
{
    if (st.size() == 0) {
        return "No participants";
    } else {
        std::vector<std::pair<std::string, int>> totals;
        std::vector<std::string> names = tokenizeString(st);
        std::vector<int>::iterator weightIt = we.begin();
        for (auto& people : names) {
            int weight = *weightIt;
            int score = calculateNameTotal(people, weight);
            totals.push_back(std::pair<std::string, int>(people, score));
            //			std::cout << people << " " << score << std::endl;
            weightIt++;
        }

        //		std::cout << "\n\nPre-sorted" << std::endl;
        //		for(auto& things:totals)
        //			std::cout << things.first << " " << things.second << std::endl;
        //
        std::sort(totals.begin(), totals.end(), sortPairByValue);

        std::cout << "\n\nPost-Sorted" << std::endl;
        for (auto& things : totals)
            std::cout << things.first << " " << things.second << std::endl;

        return totals[n].first;
    }
}

int main()
{
    std::string st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
    std::vector<int> we = { 4, 2, 1, 4, 3, 1, 2 };
    std::string sol = "Benjamin";

    std::cout << nthRank(st, we, 4) << "\n\n\n"
              << std::endl;
    //----------------------------------------------------------------------------//
    auto st2 = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
    std::vector<int> we2 = { 1, 3, 5, 5, 3, 6 };
    std::string sol2 = "Matthew";
    std::cout << nthRank(st2, we2, 2) << std::endl;

    //----------------------------------------------------------------------------//
    //
    return 0;
}
