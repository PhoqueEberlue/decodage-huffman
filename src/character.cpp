//
// Created by andrewmhdb on 06/05/22.
//

#include <iostream>
#include "character.h"

Character::Character(unsigned int characterCode, unsigned int occurrences) : characterCode(characterCode), occurrences(occurrences) {}

void Character::printCharacter() const {
    /*
     * Prints the Character's data
     */
    printf("%c %i ", this->characterCode, this->occurrences);
    for (bool bit: this->code) {
        std::cout << bit;
    }
    //std::cout << std::endl;
}

const std::vector<bool> &Character::getCode() const {
    return code;
}

void Character::setCode(const std::shared_ptr<std::vector<bool>> &codeToCopy, unsigned int codeSize) {
    /*
     * Set the huffman code of the character
     * Makes a copy of the parameter code
     */
    this->code = std::vector<bool>();
    for (int i = 0; i < codeSize; i++) {
        this->code.push_back(codeToCopy->at(i));
    }
}
