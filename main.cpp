#include <vector>
#include <iostream>
#include "boat.hpp"

int main() {
    /* Initialisation of the game board */
    std::vector<std::vector<int>> grid(10, std::vector<int>(10, 0)); // Initialisation to 0 of a 10 by 10 grid
    
    /* Initialisation of the boat fleet */
    int fleetSize = 5; // Number of boats
    int boat;
    std::vector<int> boatsLenght(fleetSize); 
    std::vector<Boat> fleet;

    boatsLenght = {5, 4, 3, 3, 2}; // Size of the different boats
    fleet.reserve(fleetSize);

    for (boat = 0; boat < fleetSize; boat++)
    {
        /* Creation of the boat fleet */
        fleet.emplace_back(static_cast<std::size_t>(boatsLenght[boat]));
    }

    std::cout << "Fleet with " << fleet.size() << " boats.\n";
    for (std::size_t i = 0; i < fleet.size(); ++i) {
        std::cout << "  Boat " << i+1 << ": size equal to " << fleet[i].size() << "\n";
    }
    
    return 0;
}