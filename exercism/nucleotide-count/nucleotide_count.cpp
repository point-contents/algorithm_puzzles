#include "nucleotide_count.h"
#include <map>
#include <stdexcept>
#include <string>

namespace nucleotide_count {
counter::counter(std::string input_dna)
{
    for (size_t i = 0; i < input_dna.size(); i++) {
        if (m_nucleotide_count_map.find(input_dna[i]) == m_nucleotide_count_map.end()) {
            throw std::invalid_argument("Invalid input");
        } else {
            m_nucleotide_count_map[input_dna[i]]++;
        }
    }
}

std::map<char, int> counter::nucleotide_counts() const
{
    return m_nucleotide_count_map;
}

int counter::count(char nucleotide_search_char) const
{
    auto it = m_nucleotide_count_map.find(nucleotide_search_char);
    if (it == m_nucleotide_count_map.end()) {
        throw std::invalid_argument("Invalid input");
    } else {
        return it->second;
    }
}
} // namespace nucleotide_count
