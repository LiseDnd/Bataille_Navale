#include "fleetPlacement.hpp"
#include "tools.hpp"

void generateBoatPosition(Boat& boat){
    int boatSize;
    int orientation;
    std::vector<int> position(2);

    boatSize = boat.size();

    /* Random selection of boat orientation (0 = vertical, 1 = horizontal) */
    orientation = randomInt(0, 1);

    /* Random selection of boat position (0 = vertical, 1 = horizontal) */
    if (orientation == 0) {
        position[0] = randomInt(0, 9 - boatSize) + randomInt(0, boatSize);
        position[1] = randomInt(0, 9);
    } else {
        position[0] = randomInt(0, 9);
        position[1] = randomInt(0, 9 - boatSize) + randomInt(0, boatSize);
    }

    boat.placement(orientation, position);
};

void generateFleetPlacement(int fleetSize, std::vector<Boat>& fleet, std::vector<std::vector<int>>& grid) {

    for (int boat = 0; boat < fleetSize; ++boat) {
        /* For each boat */
        int boatSize = static_cast<int>(fleet[boat].size());
        bool overlap = false;
        int guard = 0;

        while (!overlap && guard++ < 100000) {
            generateBoatPosition(fleet[boat]);

            int orientation = fleet[boat].orientation(); 
            int row = fleet[boat].row();
            int column = fleet[boat].col();

            /* Check that there is no overlap */
            for (int boatElement = 0; boatElement < boatSize; ++boatElement) {
                int rr = row + (orientation == 0 ? boatElement : 0);
                int cc = column + (orientation == 1 ? boatElement : 0);
                if (grid[rr][cc] != 0) { 
                    overlap = true; 
                    break; 
                }
            }
        }

        /* Store the boat's position if there is no overlap */
        if (!overlap) {
            int orientation = fleet[boat].orientation();
            int row = fleet[boat].row();
            int column = fleet[boat].col();

            for (int boatElement = 0; boatElement < boatSize; ++boatElement) {
                int rr = row + (orientation == 0 ? boatElement : 0);
                int cc = column + (orientation == 1 ? boatElement : 0);
                grid[rr][cc] = boat + 1; // Boat Id
            }
        } else {
            throw std::runtime_error("Unable to place boats");
        }
    }
}
