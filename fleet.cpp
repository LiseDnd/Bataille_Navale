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

void generateFleetPlacement(int fleetSize, std::vector<Boat>& fleet, std::vector<std::vector<int>>& grid) {

    for (int boat = 0; boat < fleetSize; ++boat) {
        /* For each boat */
        int boatSize = static_cast<int>(fleet[boat].size());
        int guard = 0;
        int attempts = 1000;
        int orientation;
        int row;
        int column;
        int rr;
        int cc;
        bool placed = false;

        while (!placed && guard++ < attempts) {
            generateBoatPosition(fleet[boat]);

            orientation = fleet[boat].orientation(); 
            row = fleet[boat].row();
            column = fleet[boat].col();

            /* Check that there is no overlap */
            bool overlap = false;
            for (int boatElement = 0; boatElement < boatSize; ++boatElement) {
                rr = row + (orientation == 0 ? boatElement : 0);
                cc = column + (orientation == 1 ? boatElement : 0);

                if (grid[rr][cc] != 0) {
                    overlap = true;
                    break; 
                }
            }

            /* Store the boat's position if there is no overlap */
            if (overlap) continue;
            for (int k = 0; k < boatSize; ++k) {
                    int rr = row    + (orientation == 0 ? k : 0);
                    int cc = column + (orientation == 1 ? k : 0);
                    grid[rr][cc] = boat + 1; // Boat Id
                }

                std::cerr << "Boat " << (boat+1) << " placed \n";

                placed = true;
            }

            if (!placed) {
                orientation = fleet[boat].orientation();
                row = fleet[boat].row();
                column = fleet[boat].col();

                std::cerr << "Unable to place boat " << (boat+1)
                          << " size=" << boatSize
                          << " after " << (guard-1) << " attempts. ";

                throw std::runtime_error("Unable to place boats");
        }
    }
}