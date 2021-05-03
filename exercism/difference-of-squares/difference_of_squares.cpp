#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares {
    int square_of_sum(int n) {
        int sum_sub_total = 0;
        for(int i = 1; i < (n+1); i++) {
            sum_sub_total += i; 
        }

        return std::pow(sum_sub_total,2);

    }
    int sum_of_squares(int n) {
        int sub_total_of_squares = 0;
        for(int i = 1; i < (n+1); i++)
        {
            int squared_value = std::pow(i, 2);
            sub_total_of_squares += squared_value;
        }
        return sub_total_of_squares;
    }

    int difference(int n) {
        int square_of_sum_value = square_of_sum(n);
        int sum_of_consecutive_squares = sum_of_squares(n);
        return square_of_sum_value - sum_of_consecutive_squares;
    }

}  // namespace difference_of_squares
