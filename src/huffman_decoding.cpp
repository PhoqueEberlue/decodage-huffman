//
// Created by andrewmhdb on 08/05/22.
//

#include "huffman_decoding.h"
#include "alphabet.h"
#include "tree.h"

void mainDecode(const std::string& filePath) {
    std::shared_ptr<Alphabet> alphabet = std::make_shared<Alphabet>();

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

    tree->decodeFile("../texts/textesimple_comp.bin", "../texts/textesimple_res.txt");
}