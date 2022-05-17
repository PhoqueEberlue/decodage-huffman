//
// Created by andrewmhdb on 15/05/22.
//

#ifndef DECODAGE_HUFFMAN_TREE_H
#define DECODAGE_HUFFMAN_TREE_H

#include "node.h"
#include <list>
#include "alphabet.h"

class Tree {
private:
    std::list<std::shared_ptr<Node>> *nodeList = new std::list<std::shared_ptr<Node>>();
    Node *root;

public:
    Tree() = default;

    void generateNodeList(Alphabet *alphabet);

    void printNodeList();
};

#endif //DECODAGE_HUFFMAN_TREE_H
