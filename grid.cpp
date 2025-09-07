#include <iostream>
#include "grid.hpp"

void targetResult(Fleet& fleet, int outRow, int outCol, int& hit) {
    int boatId = 0;

    std::vector<std::vector<int>>& grid  = fleet.grid();
    std::vector<Boat>& boats = fleet.fleet(); 

    if (0 == grid[outRow][outCol]) {
        std::cout << "Water\n\n";
        grid[outRow][outCol] = -1;
    }
    else if (-1 == grid[outRow][outCol]) {
        std::cout << "Cell already played\n\n";
    }
    else {
        boatId = grid[outRow][outCol];
        grid[outRow][outCol] = -1;
        hit++;
        boats[boatId - 1].hited();
        if (boats[boatId - 1].isSunk())
            std::cout << "Boat sunk\n\n";
        else
            std::cout << "Boat hit\n\n";
    }
}