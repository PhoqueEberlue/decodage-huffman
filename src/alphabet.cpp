//
// Created by andrewmhdb on 06/05/22.
//

#include "alphabet.h"
#include <fstream>
#include <iostream>

void Alphabet::generateAlphabet(const std::string& filePath) {
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
            auto *new_char = new Character(character_code, occurrences);
            this->addCharacterToList(*new_char);
        }
    } else {
        printf("The specified path didn't match any file");
    }
}


