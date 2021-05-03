#include "two_fer.h"
#include <vector>
#include <string>
#include <regex>
#include <algorithm>

namespace two_fer
{
    std::string two_fer(std::string name) {
        std::string default_string = "One for you, one for me.";
        std::string two_fer_return = "";
        std::regex theirName("you");
        if(name == "") {
            two_fer_return = default_string;
        } else {
            two_fer_return = std::regex_replace(default_string, theirName, name);
        }
        return two_fer_return;
    }
} // namespace two_fer

