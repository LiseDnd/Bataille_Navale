#include "boat.hpp"
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
        position[0] = randomInt(0, 9 - (boatSize - 1));
        position[1] = randomInt(0, 9);
    } else {
        position[0] = randomInt(0, 9);
        position[1] = randomInt(0, 9 - (boatSize - 1));
    }

    boat.placement(orientation, position);
};