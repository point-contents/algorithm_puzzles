#include "rna_transcription.h"
#include <string>
#include <map>

namespace rna_transcription {
        std::map<char, char> make_map() {
            std::map<char, char> translation_map = 
            {{'G','C'},
            {'C','G'},
            {'T','A'},
            {'A','U'}};
            return translation_map; 
        }

        char to_rna(char dna_char) {
            auto dna_to_rna_map = make_map();
            auto it = dna_to_rna_map.find(dna_char);
            return it->second;
        }

        std::string to_rna(std::string dna_string) {
            auto dna_to_rna_map = make_map();
            std::string output_rna_string = "";
            for(auto& elements: dna_string) {
                auto it = dna_to_rna_map.find(elements); 
                output_rna_string.push_back(it->second);
            }
            return output_rna_string;
        }
}  // namespace rna_transcription
