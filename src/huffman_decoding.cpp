//
// Created by andrewmhdb on 08/05/22.
//

#include "huffman_decoding.h"

void mainDecode(const std::string& filePath) {
    std::unique_ptr<Alphabet> alphabet(new Alphabet());
    alphabet->generateAlphabet(filePath);
    alphabet->sortAlphabetByOccurrences();
    alphabet->sortAlphabetByASCIICodes();
    alphabet->printAlphabet();
}