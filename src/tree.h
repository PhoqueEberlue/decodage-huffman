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
    std::shared_ptr<Node> root = nullptr;
    unsigned int depth;
    std::shared_ptr<Node> currentNode = nullptr;
    std::shared_ptr<Alphabet> alphabet;


public:
    Tree() = default;

    void generateNodeList(const std::shared_ptr<Alphabet>& alphabetParam);

    void printNodeList();

    void generateTree();

    void insertNewNode(const std::shared_ptr<Node>& newNode);

    void printTree(std::shared_ptr<Node> root, int space);

    [[nodiscard]] const std::shared_ptr<Node> &getRoot() const;

    unsigned int getDepth();

    void callGenerateCodes();

    bool moveInTree(bool isRight);

    void decodeFile(const std::string& filePath, const std::string& outPutFilePath);
};

#endif //DECODAGE_HUFFMAN_TREE_H
