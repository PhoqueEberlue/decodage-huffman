//
// Created by andrewmhdb on 06/05/22.
//

#include "character.h"

Character::Character(unsigned int characterCode, unsigned int occurrences) : characterCode(characterCode), occurrences(occurrences) {}

void Character::printCharacter() const {
    /*
     * Prints the Character's data
     */
    printf("%c %i\n", this->characterCode, this->occurrences);
}