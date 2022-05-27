//
// Created by andrewmhdb on 06/05/22.
//

#include "alphabet.h"
#include <fstream>
#include <iostream>

void Alphabet::generateAlphabet(const std::string &filePath) {
    /*
     * Generates the Alphabet corresponding to the given file
     * Parameter: the path of the file
     * Return: void, modif directly the Alphabet class
     */

    std::fstream alphabetFile;
    alphabetFile.open(filePath, std::ios::in);

    // if the file is open
    if (alphabetFile.is_open()) {

        std::string line;

        // Get the first line which is the number of total occurrences in the file
        getline(alphabetFile, line);
        std::basic_string<char> num = line.substr(0, line.length());
        std::cout << num << std::endl;
        this->setNumCharacters(stoul(num));

        // loop through each line of the file
        while (getline(alphabetFile, line)) {

            // Get the character
            std::basic_string<char> current_char = line.substr(0, 1);
            const char *conv_to_char = current_char.c_str();
            unsigned int character_code = int(*conv_to_char);
            std::cout << character_code << std::endl;

            // Get the number of occurrences of the character
            unsigned int occurrences = stoul(line.substr(2, line.length()));
            std::cout << occurrences << std::endl;

            // Create a new Character class and adds it to the list
            std::shared_ptr<Character> new_char = std::make_unique<Character>(character_code, occurrences);
            this->addCharacterToList(new_char);
        }
    } else {
        printf("The specified path didn't match any file");
    }
}

void Alphabet::sortAlphabetByOccurrences() {
    /*
     * Sort the Alphabet by occurrences
     * Does not return anything, modifies the list directly
     */
    this->listCharacter->sort(
            [](std::shared_ptr<Character> const &a, std::shared_ptr<Character> const &b) -> bool {
                return a->getOccurrences() < b->getOccurrences();
            });
}

void Alphabet::sortAlphabetByASCIICodes() {
    /*
     * Sort the Alphabet by ASCII Codes (keeps the occurrences order)
     * Does not return anything, modifies the list directly
     */
    this->listCharacter->sort([](std::shared_ptr<Character> const &a, std::shared_ptr<Character> const &b) -> bool {
        return a->getCharacterCode() < b->getCharacterCode() && a->getOccurrences() == b->getOccurrences();
    });
}

void Alphabet::printAlphabet() {
    /*
     * Prints each Character of the Alphabet
     */
    for (const std::shared_ptr<Character>& character: *this->listCharacter) {
        character->printCharacter();
        printf("\n");
    }
}

unsigned int Alphabet::getNumCharacters() const {
    return num_characters;
}
