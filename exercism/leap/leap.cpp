#include "leap.h"

namespace leap {
    bool divisible_by_four(int year) { return (year % 4 == 0); }
    bool divisible_by_hundred(int year) { return (year % 100 == 0); }
    bool divisible_by_four_hundred(int year) { return (year % 400 == 0); }

    bool is_leap_year(int year) {
        return ((divisible_by_four(year) && !divisible_by_hundred(year)) || 
                divisible_by_four_hundred(year));
    }
}  // namespace leap



