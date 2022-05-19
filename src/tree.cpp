//
// Created by andrewmhdb on 15/05/22.
//
#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include <bitset>
#include <functional>
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

void findDepth(int *res, std::shared_ptr<Node> root, int depth) {
    /*
     * update the value `res` to get the maximum depth of the tree
     */
    // if the current node is a no char node
    if (root->getCharacter()->getCharacterCode() == 0) {
        findDepth(res, root->getLeftChild(), depth + 1);
        findDepth(res, root->getRightChild(), depth + 1);
    }
        // if current node is a leaf and the max depth is < to the current depth
    else if (*res < depth) {
        *res = depth;
    }
}

unsigned int Tree::getDepth() {
    /*
     * Compute the depth of the tree and save it to the Object
     */
    int res = 0;
    findDepth(&res, this->getRoot(), 0);
    this->depth = res;

    return res;
}

void generateCodes(std::shared_ptr<Node> root, std::shared_ptr<std::vector<bool>> code, unsigned int depth) {
    /*
    * Generate binary code for each character
    */
    // if the current node is a no char node
    if (root->getCharacter()->getCharacterCode() == 0) {
        auto it = code->begin();
        std::advance(it, depth);
        code->insert(it, false);
        ++depth;
        generateCodes(root->getLeftChild(), code, depth);

        code->insert(it, true);
        generateCodes(root->getRightChild(), code, depth);
    } else {
        root->getCharacter()->setCode(code, depth);
    }
}

void Tree::callGenerateCodes() {
    auto code = std::make_shared<std::vector<bool>>(this->depth);
    generateCodes(this->root, code, 0);
}