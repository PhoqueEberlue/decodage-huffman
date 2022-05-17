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
    std::list<std::shared_ptr<Character>> *listCharacter = new std::list<std::shared_ptr<Character>>();
    unsigned int num_characters = 0;

public:
    Alphabet() = default;
    void setNumCharacters(int numCharacters) { this->num_characters = numCharacters; }

    std::list<std::shared_ptr<Character>> *getListCharacter() { return this->listCharacter; }

    void addCharacterToList(const std::shared_ptr<Character>& character) { this->listCharacter->push_front(character);}

    void generateAlphabet(const std::string& filePath);

    void sortAlphabetByOccurrences();

    void sortAlphabetByASCIICodes();

    void printAlphabet();
};

#endif //DECODAGE_HUFFMAN_ALPHABET_H
