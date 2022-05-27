//
// Created by andrewmhdb on 15/05/22.
//
#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include <bitset>
#include <functional>
#include <fstream>
#include "tree.h"
#include "node.h"

void Tree::generateNodeList(const std::shared_ptr<Alphabet>& alphabetParam) {
    /*
     * Generates the node list
     */
    // for each character in the alphabetParam, create a node
    for (const std::shared_ptr<Character> &character: *alphabetParam->getListCharacter()) {
        std::shared_ptr<Node> node = std::make_shared<Node>(character);
        this->nodeList->push_back(node);
    }
    this->alphabet = alphabetParam;
}

void Tree::printNodeList() {
    /*
     * Prints the node list
     */
    for (const std::shared_ptr<Node>& node: *this->nodeList) {
        node->printNode();
        std::cout << '|';
    }
    std::cout << std::endl;
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
            if (node->getCharacter()->getOccurrences() >= newNode->getCharacter()->getOccurrences()) {
                break;
            }
            i++;
        }

        auto it = this->nodeList->begin();
        std::advance(it, i);

        this->nodeList->insert(it, newNode);
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
        this->printNodeList();
    }

    // The last node is then the root of the tree
    this->root = nodeList->front();
    this->currentNode = this->root;
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

bool Tree::moveInTree(bool isRight) {
    /*
     * Updates the currentNode to move in the tree
     * Returns true if the next node is a leaf, false instead
     *
     */
    if (isRight) {
        this->currentNode = this->currentNode->getRightChild();
    } else {
        this->currentNode = this->currentNode->getLeftChild();
    }

    return this->currentNode->isLeaf1();
}

void Tree::decodeFile(const std::string &filePath, const std::string &outPutFilePath) {
    /*
     * Decode the file given in parameter
     */

    // opens the two files
    std::ifstream binaryFile(filePath, std::ios::out | std::ios::binary);
    std::fstream outPutFile;
    outPutFile.open(outPutFilePath, std::ios::out);

    char charSeq;

    unsigned int characterCount = 0;

    if (binaryFile.is_open() && outPutFile.is_open()) {
        // while we haven't reached the end of the file
        while (!binaryFile.eof()) {

            // read byte
            binaryFile.read(&charSeq, 1);
            std::bitset<8> currentByte(charSeq);

            // std::cout << currentByte << std::endl;

            // For each bit in the byte
            for (int i = 7; i >= 0; i--) {
                // move in the tree and if it's a leaf
                if (this->moveInTree(currentByte.test(i))) {
                    characterCount++;

                    printf("%c", this->currentNode->getCharacter()->getCharacterCode());
                    outPutFile << (char) this->currentNode->getCharacter()->getCharacterCode();
                    this->currentNode = this->root;
                }

                // if we decoded all characters of the text break
                if (characterCount == this->alphabet->getNumCharacters()) {
                    break;
                }
            }
        }
    }

    binaryFile.close();
    outPutFile.close();
}
