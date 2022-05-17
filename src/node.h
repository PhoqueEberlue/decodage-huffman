//
// Created by andrewmhdb on 15/05/22.
//

#ifndef DECODAGE_HUFFMAN_NODE_H
#define DECODAGE_HUFFMAN_NODE_H

#include <memory>
#include <iostream>
#include <utility>
#include "character.h"

class Node {
private:
    std::shared_ptr<Node> leftChild;
    std::shared_ptr<Node> rightChild;
    std::shared_ptr<Character> character;
    bool isLeaf;


public:
    explicit Node(std::shared_ptr<Character> character) : character(std::move(character)), isLeaf(true),
                                                          leftChild(nullptr), rightChild(nullptr) {}

    Node(std::shared_ptr<Node> leftChild, std::shared_ptr<Node> rightChild, std::shared_ptr<Character> character):
              leftChild(std::move(leftChild)),
              rightChild(std::move(rightChild)),
              isLeaf(false),
              character(std::move(character)) {}

    ~Node() { std::cout << "deleting node" << std::endl; }

    [[nodiscard]] std::shared_ptr<Node> getLeftChild() const {
        return leftChild;
    }

    void setLeftChild(std::shared_ptr<Node> leftChild) {
        Node::leftChild = leftChild;
    }

    [[nodiscard]] std::shared_ptr<Node> getRightChild() const {
        return rightChild;
    }

    void setRightChild(std::shared_ptr<Node> rightChild) {
        Node::rightChild = rightChild;
    }

    [[nodiscard]] std::shared_ptr<Character> getCharacter() const {
        return character;
    }

    void setCharacter(std::shared_ptr<Character> character) {
        Node::character = std::move(character);
    }

    [[nodiscard]] bool isLeaf1() const {
        return isLeaf;
    }

    void setIsLeaf(bool isLeaf) {
        Node::isLeaf = isLeaf;
    }

    void printNode() const;
};

#endif //DECODAGE_HUFFMAN_NODE_H
