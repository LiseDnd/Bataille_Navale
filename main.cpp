#include <vector>
#include <iostream>
#include "fleet.hpp"

int main() {
    /* Initialisation of the game board */
    std::vector<std::vector<int>> grid(10, std::vector<int>(10, 0)); // Initialisation to 0 of a 10 by 10 grid
    
    /* Initialisation of the boat fleet */
    int fleetSize = 5; // Number of boats
    std::vector<int> boatsLenght(fleetSize); 
    std::vector<Boat> fleet;

    boatsLenght = {5, 4, 3, 3, 2}; // Size of the different boats
    fleet.reserve(fleetSize);

    createFleet(fleetSize, boatsLenght, fleet);
    
    return 0;
}