//
// Created by andrewmhdb on 08/05/22.
//

#include "huffman_decoding.h"
#include "alphabet.h"
#include "tree.h"

void mainDecode(const std::string& filePath) {
    auto *alphabet = new Alphabet();

    alphabet->generateAlphabet(filePath);
    alphabet->sortAlphabetByOccurrences();
    alphabet->sortAlphabetByASCIICodes();
    alphabet->printAlphabet();

    auto *tree = new Tree();

    tree->generateNodeList(alphabet);
    tree->printNodeList();

  
}