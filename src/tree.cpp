//
// Created by andrewmhdb on 15/05/22.
//

#include <iostream>
#include "tree.h"
#include "node.h"

void Tree::generateNodeList(Alphabet *alphabet) {
    for (const std::shared_ptr<Character>& character: *alphabet->getListCharacter()) {
        std::shared_ptr<Node> node = std::make_unique<Node>(character);
        this->nodeList->push_back(node);
    }
}

void Tree::printNodeList() {
    for (std::shared_ptr<Node> node: *this->nodeList) {
        node->printNode();
        std::cout << &node << std::endl;
    }
}