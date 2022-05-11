//
// Created by andrewmhdb on 06/05/22.
//

#ifndef DECODAGE_HUFFMAN_CHARACTER_H
#define DECODAGE_HUFFMAN_CHARACTER_H

class Character {
public:
    Character(unsigned int characterCode, unsigned int occurrences);

private:
    unsigned int characterCode;
    unsigned int occurrences;
};

#endif //DECODAGE_HUFFMAN_CHARACTER_H
