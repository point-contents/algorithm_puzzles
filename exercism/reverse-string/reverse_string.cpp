#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {
    std::string reverse_string(std::string input_to_reverse) {
        std::reverse(input_to_reverse.begin(), input_to_reverse.end());
        return input_to_reverse;
    }
}  // namespace reverse_string
