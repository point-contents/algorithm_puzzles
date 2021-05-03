#include <map>
#include <string>

#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

namespace nucleotide_count {
class counter {
    std::map<char, int> m_nucleotide_count_map {
        { 'A', 0 }, { 'T', 0 }, { 'C', 0 }, { 'G', 0 }
    };

public:
    counter(std::string input_dna);
    std::map<char, int> nucleotide_counts() const;
    int count(char nucleotide_search_char) const;
};
} // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H
