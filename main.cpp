#include <vector>
#include <iostream>
#include "fleet.hpp"
#include "tools.hpp"
#include "grid.hpp"

int main() {
    /* Game initialisation */
    int row;
    int column;
    Fleet fleet;
    fleet.placeFleet(); // Place the randomly on a 10x10 grid

    std::vector<std::vector<int>>& grid  = fleet.grid();

    for (row = 0; row < 10; ++row) {
        for (column = 0; column < 10; ++column) {
            std::cout << grid[row][column] << ' ';
        }
        std::cout << "\n";
    }

    /* Request for cell to target to player */
    int outRow;
    int outCol;
    int maxHit = 0;
    int hit = 0;

    for (int len : fleet.boatsLenght()) {
        maxHit += len;
    }

    for (;;)
    {
        readCoordinates(outRow, outCol);
        targetResult(fleet, outRow, outCol, hit);

        if (maxHit == hit) {
            std::cout << "Congratulations, you have won!";
            break;
        }

    }
    
    return 0;
}