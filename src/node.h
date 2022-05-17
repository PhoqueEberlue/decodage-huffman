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
    Node *leftChild;
    Node *rightChild;
    std::shared_ptr<Character> character;
    bool isLeaf;


    Node(Node *leftChild, Node *rightChild) : leftChild(leftChild), rightChild(rightChild), isLeaf(false), character(
            nullptr) {}

public:
    explicit Node(std::shared_ptr<Character> character) : character(std::move(character)), isLeaf(true), leftChild(nullptr), rightChild(nullptr) {}

    ~Node() { std::cout << "MACRON EXPLOSION" << std::endl ; }

    [[nodiscard]] Node *getLeftChild() const {
        return leftChild;
    }

    void setLeftChild(Node *leftChild) {
        Node::leftChild = leftChild;
    }

    [[nodiscard]] Node *getRightChild() const {
        return rightChild;
    }

    void setRightChild(Node *rightChild) {
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
