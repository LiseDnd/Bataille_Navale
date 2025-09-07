#include <vector>
#include <iostream>
#include <ctime>
#include "fleet.hpp"
#include "tools.hpp"
#include "grid.hpp"

int main() {
    /* Random initialisation */
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    /* Game initialisation */
    Fleet fleet;
    fleet.placeFleet(); // Place the randomly on a 10x10 grid

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
        printGrid(fleet);

        if (maxHit == hit) {
            std::cout << "Congratulations, you have won!";
            break;
        }

    }
    
    return 0;
}