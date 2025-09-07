#include <iostream>
#include <iomanip>
#include "grid.hpp"

void targetResult(Fleet& fleet, int outRow, int outCol, int& hit) {
    int boatId = 0;

    std::vector<std::vector<int>>& grid  = fleet.grid();
    std::vector<Boat>& boats = fleet.fleet(); 

    if (0 == grid[outRow][outCol]) {
        std::cout << "Water\n\n";
        grid[outRow][outCol] = -999;
    }
    else if (grid[outRow][outCol] < 0) {
        std::cout << "Cell already played\n\n";
    }
    else {
        boatId = grid[outRow][outCol];
        grid[outRow][outCol] = -boatId;
;
        hit++;
        boats[boatId - 1].hited();
        if (boats[boatId - 1].isSunk())
            std::cout << "Boat sunk\n\n";
        else
            std::cout << "Boat hit\n\n";
    }
}

void printGrid(Fleet& fleet) {
    std::vector<std::vector<int>>& grid  = fleet.grid();
    std::vector<Boat>& boats = fleet.fleet(); 

    std::vector<bool> sunk(boats.size() + 1, false);
    for (std::size_t i = 0; i < boats.size(); ++i) {
        if (boats[i].isSunk()) sunk[i + 1] = true;
    }

    // Column
    std::cout << "    ";
    for (int column = 0; column < static_cast<int>(grid[0].size()); ++column) {
        char letter = static_cast<char>('A' + column);
        std::cout << letter << ' ';
    }
    std::cout << "\n";

    // Row
    for (int row = 0; row < static_cast<int>(grid.size()); ++row) {
        std::cout << std::setw(3) << (row + 1) << ' '; 
        for (int column = 0; column < static_cast<int>(grid[row].size()); ++column) {
            int element = grid[row][column];
            char character = '?';

            if (element >= 0) {
                character = '.';  
            } else if (element == -999) {
                character = 'o'; 
            } else if (element < 0 && element != -999) {
                if (boats[std::abs(element) - 1].isSunk())
                    character = 'S'; 
                else
                    character = 'X'; 
            }

            std::cout << character << ' ';
        }
        std::cout << "\n";
    }

    std::cout << "\nLegend: .=not played  o=water  X=hit  S=sunk";
    std::cout << "\n\n";
}