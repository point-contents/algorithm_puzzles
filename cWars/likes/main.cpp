#include <iostream>
#include <string>
#include <vector>

#define LOG(x) std::cout << x << std::endl

std::string likes(const std::vector<std::string>& names)
{
    if (names.size() == 0) {
        return "no one likes this";
    }
    if (names.size() == 1) {
        return names.front() + " likes this";
    } else if (names.size() < 3 && (names.size() > 1)) {
        std::string twoPeople = "and ";
        twoPeople.insert(0, names.front() + " ");
        twoPeople.append(names.back() + " like this");

        return twoPeople;
    }

    else if (names.size() == 3) {
        std::string threePeople = " and ";
        threePeople.insert(0, names.front() + ", " + names.at(1));
        threePeople.append(names.back() + " like this");

        return threePeople;
    }

    else if (names.size() > 3) {
        std::string lotsOfPeople = names.front() + ", " + names.at(1) + " and ";

        int countOfOthers = names.size() - 2;
        lotsOfPeople.append(std::to_string(countOfOthers) + " others like this");

        return lotsOfPeople;
    } else {
        return "error";
    }
}

int main()
{
    std::string none = likes({});
    std::string single = likes({ "richard" });
    std::string two = likes({ "richard", "andrew" });
    std::string three = likes({ "richard", "andrew", "tim" });
    std::string four = likes({ "richard", "andrew", "tim", "reihana" });
    std::string heaps = likes({ "richard", "andrew", "tim", "reihana", "richard", "andrew", "tim", "reihana", "andrew", "tim", "reihana", "richard", "andrew", "tim", "reihana" });

    LOG("None");
    LOG(none);
    LOG("Single");
    LOG(single);
    LOG("Double");
    LOG(two);
    LOG("Triple");
    LOG(three);
    LOG("More");
    LOG(four);
    LOG("Heaps");
    LOG(heaps);

    //	LOG("\nWho?");
    //	std::vector<std::string> myArray;
    //	std::cin >> myArray;
    return 0;
}
