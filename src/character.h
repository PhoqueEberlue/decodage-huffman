//
// Created by andrewmhdb on 06/05/22.
//

#ifndef DECODAGE_HUFFMAN_CHARACTER_H
#define DECODAGE_HUFFMAN_CHARACTER_H

#include <iostream>
#include <memory>
#include <vector>

class Character {

private:
    unsigned int characterCode;
    unsigned int occurrences;
    std::vector<bool> code;

public:
    Character(unsigned int characterCode, unsigned int occurrences);

    explicit Character(unsigned int occurrences) : occurrences(occurrences), characterCode(0) {}

    ~Character() { std::cout << "Character's destructor called" << std::endl; }

    [[nodiscard]] unsigned int getOccurrences() const { return this->occurrences; }

    [[nodiscard]] unsigned int getCharacterCode() const { return this->characterCode; }

    void printCharacter() const;

    void setCode(const std::shared_ptr<std::vector<bool>> &codeToCopy, unsigned int codeSize);

    [[nodiscard]] const std::vector<bool> &getCode() const;
};

#endif //DECODAGE_HUFFMAN_CHARACTER_H
