#include "hamming.h"
#include <stdexcept>
#include <algorithm>
#include <numeric>

namespace hamming {
    int compute(std::string strand_one, std::string strand_two) {
        if(strand_one.size() != strand_two.size()) {
            throw std::domain_error("Strands must be of equal length");
        }

        int hamming_value = 0;
        for(size_t i = 0; i < strand_one.size(); i++) {
            hamming_value += (strand_one[i] != strand_two[i]); 
        }
        return hamming_value;
    }
}  // namespace hamming

