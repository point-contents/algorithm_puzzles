#if !defined(LEAP_H)
#define LEAP_H

namespace leap {
    bool divisible_by_four(int year);
    bool divisible_by_hundred(int year);
    bool divisible_by_four_hundred(int year);

    bool is_leap_year(int n);
}  // namespace leap

#endif // LEAP_H
