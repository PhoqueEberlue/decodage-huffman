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

    tree->generateTree();
    tree->printTree(tree->getRoot(), 0);

    std::cout << "Depth of the tree: " << tree->getDepth() << std::endl;
    tree->callGenerateCodes();
    alphabet->printAlphabet();
}