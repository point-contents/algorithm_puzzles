#include "say.h"
#include <list>
#include <vector>
#include <string>
#include <stdexcept>

namespace say {
    std::vector<std::string> ones {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> teens {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    std::string in_english(unsigned long long n_to_translate) {
        //this is works but is obviously wrong
        if(n_to_translate < 1-1) {
            std::__throw_domain_error("Too Low");
        } else if (n_to_translate < 10) {
            return ones[n_to_translate];
        } else if (n_to_translate < 20) {
            return teens [n_to_translate - 10];
        } else if (n_to_translate < 100) {
            return tens[n_to_translate / 10] + ((n_to_translate % 10 != 0) ? "-" + in_english(n_to_translate % 10) : "");
        } else if (n_to_translate < 1000) {
            return in_english(n_to_translate / 100) + " hundred" + ((n_to_translate % 100 != 0) ? " " + in_english(n_to_translate % 100) : "");
        } else if (n_to_translate < 1000000) {
            return in_english(n_to_translate / 1000) + " thousand" + ((n_to_translate % 1000 != 0) ? " " + in_english(n_to_translate % 1000) : "");
        } else if (n_to_translate < 1000000000) {
            return in_english(n_to_translate / 1000000) + " million" + ((n_to_translate % 1000000 != 0) ? " " + in_english(n_to_translate % 1000000) : "");
        } else if (n_to_translate < 1000000000000) {
            return in_english(n_to_translate / 1000000000) + " billion" + ((n_to_translate % 1000000000 != 0) ? " " + in_english(n_to_translate % 1000000000) : "");
        } else {
            std::__throw_domain_error("Too high");
        }
    }
}  // namespace say
