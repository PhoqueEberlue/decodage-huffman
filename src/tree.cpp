//
// Created by andrewmhdb on 15/05/22.
//

#include <iostream>
#include "tree.h"
#include "node.h"

void Tree::generateNodeList(Alphabet *alphabet) {
    /*
     * Generates the node list
     */
    // for each character in the alphabet, create a node
    for (const std::shared_ptr<Character> &character: *alphabet->getListCharacter()) {
        std::shared_ptr<Node> node = std::make_shared<Node>(character);
        this->nodeList->push_back(node);
    }
}

void Tree::printNodeList() {
    /*
     * Prints the node list
     */
    for (std::shared_ptr<Node> node: *this->nodeList) {
        node->printNode();
        std::cout << &node << std::endl;
    }
}

void Tree::insertNewNode(const std::shared_ptr<Node> &newNode) {
    /*
     * Inserts a new node to the node list
     */

    // if the node to insert is greater than the last element of the list
    if (!this->nodeList->empty() &&
        newNode->getCharacter()->getOccurrences() > this->nodeList->back()->getCharacter()->getOccurrences()) {
        this->nodeList->push_back(newNode);

    } else {

        unsigned int i = 0;

        // loop through the list to find the index to insert
        for (const std::shared_ptr<Node> &node: *this->nodeList) {
            if (node->getCharacter()->getOccurrences() <= newNode->getCharacter()->getOccurrences()) {
                break;
            }
            i++;
        }

        auto it = this->nodeList->begin();
        std::advance(it, i);

        this->nodeList->insert(this->nodeList->cbegin(), newNode);
    }
}

void Tree::generateTree() {
    /*
     * Generates the Huffman tree
     * Must have generated the nodeList before
     */
    // while there is exactly not 1 item in the list
    while (this->nodeList->size() != 1) {
        // gets the first node
        std::shared_ptr<Node> node1 = this->nodeList->front();
        // delete it from the list
        this->nodeList->pop_front();

        // gets the second node
        std::shared_ptr<Node> node2 = this->nodeList->front();
        // delete it from the list
        this->nodeList->pop_front();

        // create our new node
        unsigned int freqSum = node1->getCharacter()->getOccurrences() + node2->getCharacter()->getOccurrences();
        std::shared_ptr<Character> newChar = std::make_shared<Character>(freqSum);

        std::shared_ptr<Node> newNode = std::make_shared<Node>(node1, node2, newChar);

        // inserting the new node to the list
        this->insertNewNode(newNode);
    }

    // The last node is then the root of the tree
    this->root = nodeList->front();
}

void Tree::printTree(std::shared_ptr<Node> root, int space) {
    /*
     * Clean print of a tree
     */
    if (root == nullptr)
        return;
    space += 1;
    this->printTree(root->getRightChild(), space);
    for (int i = 1; i < space; ++i)
        printf("\t");
    printf("%c %i\n", root->getCharacter()->getCharacterCode(), root->getCharacter()->getOccurrences());
    this->printTree(root->getLeftChild(), space);
}

const std::shared_ptr<Node> &Tree::getRoot() const {
    return root;
}
