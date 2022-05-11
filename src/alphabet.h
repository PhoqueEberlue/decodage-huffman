//
// Created by andrewmhdb on 06/05/22.
//

#ifndef DECODAGE_HUFFMAN_ALPHABET_H
#define DECODAGE_HUFFMAN_ALPHABET_H

#include "character.h"
#include <list>
#include <memory>


class Alphabet {
private:
    std::list<Character> listCharacter = {};
    unsigned int num_characters = 0;

public:
    Alphabet() = default;
    void setNumCharacters(int numCharacters) { this->num_characters = numCharacters; }
    void addCharacterToList(Character character) { this->listCharacter.push_front(character);}
    void generateAlphabet(const std::string& filePath);
};

#endif //DECODAGE_HUFFMAN_ALPHABET_H
