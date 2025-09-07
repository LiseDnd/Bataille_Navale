#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <utility>

int randomInt(int min, int max) {
    return min + std::rand() % (max - min + 1);
}

bool readCoordinates(int& outRow, int& outCol) {
    for (;;) {// Infinite loop
        char colChar;
        int column;
        int row;
        std::string playerInput;

        std::cout << "Targeted cell, for example D7: ";

        /* Retrieve the player's input and remove white spaces */
        if (!std::getline(std::cin >> std::ws, playerInput)) {
            return false;
        }

        /* If the input is empty, the loop starts again */
        if (playerInput.empty()) continue;

        /* Loading the first character (letter capitalised if necessary) */
        colChar = static_cast<char>(std::toupper(static_cast<unsigned char>(playerInput[0])));
        column = colChar - 'A';  // Converts letters into numbers (A = 0)

        /* Loading the second character */
        if (playerInput.size() == 2 && std::isdigit(static_cast<unsigned char>(playerInput[1]))) {
            row = (playerInput[1] - '0') - 1; 
        } 
        else if (playerInput.size() == 3 && playerInput.substr(1) == "10") {
            row = 9;
        }
        else {
            row = 999;
        }

        if (0 <= column && column < 10 && 0 <= row && row < 10) {
            outRow = row;
            outCol = column;
            return true;
        }
        else {
            std::cout << "Invalid format\n\n";
        }
    }
}
