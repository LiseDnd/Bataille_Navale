#include <iostream>
#include "fleet.hpp"

void createFleet(int fleetSize, std::vector<int>& boatsLenght, std::vector<Boat>& fleet) {
    int boat;

    for (boat = 0; boat < fleetSize; boat++)
    {
        /* Creation of the boat fleet */
        fleet.emplace_back(static_cast<std::size_t>(boatsLenght[boat]));
    }

    std::cout << "Fleet with " << fleet.size() << " boats.\n";
    for (std::size_t i = 0; i < fleet.size(); ++i) {
        std::cout << "  Boat " << i+1 << ": size equal to " << fleet[i].size() << "\n";
    }
}