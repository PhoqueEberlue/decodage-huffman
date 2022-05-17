//
// Created by andrewmhdb on 06/05/22.
//

#ifndef DECODAGE_HUFFMAN_CHARACTER_H
#define DECODAGE_HUFFMAN_CHARACTER_H
#include <iostream>

class Character {
public:
    Character(unsigned int characterCode, unsigned int occurrences);

    ~Character() { std::cout << "MACRON DESTITUTION" << std::endl; }

    [[nodiscard]] unsigned int getOccurrences() const { return this->occurrences; }

    [[nodiscard]] unsigned int getCharacterCode() const { return this->characterCode; }

    void printCharacter() const;

private:
    unsigned int characterCode;
    unsigned int occurrences;
};

#endif //DECODAGE_HUFFMAN_CHARACTER_H
