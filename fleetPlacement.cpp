#include "fleetPlacement.hpp"
#include "tools.hpp"

#include <iostream>

void generateBoatPosition(Boat& boat){
    int boatSize;
    int orientation;
    std::vector<int> position(2);

    boatSize = boat.size();

    /* Random selection of boat orientation (0 = vertical, 1 = horizontal) */
    orientation = randomInt(0, 1);

    /* Random selection of boat position (0 = vertical, 1 = horizontal) */
    if (orientation == 0) {
        position[0] = randomInt(0, 9 - (boatSize - 1));
        position[1] = randomInt(0, 9);
    } else {
        position[0] = randomInt(0, 9);
        position[1] = randomInt(0, 9 - (boatSize - 1));
    }

    boat.placement(orientation, position);
};

void generateFleetPlacement(int fleetSize, std::vector<Boat>& fleet, std::vector<std::vector<int>>& grid) {

    for (int boat = 0; boat < fleetSize; ++boat) {
        /* For each boat */
        int boatSize = static_cast<int>(fleet[boat].size());
        int guard = 0;
        int attempts = 1000;
        bool placed = false;

        while (!placed && guard++ < attempts) {
            generateBoatPosition(fleet[boat]);

            int orientation = fleet[boat].orientation(); 
            int row = fleet[boat].row();
            int column = fleet[boat].col();

            /* Check that there is no overlap */
            bool overlap = false;
            for (int boatElement = 0; boatElement < boatSize; ++boatElement) {
                int rr = row + (orientation == 0 ? boatElement : 0);
                int cc = column + (orientation == 1 ? boatElement : 0);

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
                int orientation = fleet[boat].orientation();
                int row = fleet[boat].row();
                int column = fleet[boat].col();

                std::cerr << "Unable to place boat " << (boat+1)
                          << " size=" << boatSize
                          << " after " << (guard-1) << " attempts. ";

                throw std::runtime_error("Unable to place boats");
        }
    }
}
