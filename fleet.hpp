#pragma once
#include <vector>
#include <stdexcept>

class Boat {
    std::size_t size_;            
    std::vector<int> location_{0, 0, 0}; 

public:
    explicit Boat(std::size_t size) : size_(size) {
        if (size_ == 0) throw std::invalid_argument("Boat size must be > 0");
    }

    std::size_t size() const noexcept { return size_; }

    std::vector<int> const& placement(int orientation, const std::vector<int>& position) {
        if (orientation != 0 && orientation != 1)
            throw std::invalid_argument("ERROR : orientation must be 0 (vertical) or 1 (horizontal)");
        if (position.size() < 2)
            throw std::invalid_argument("ERROR : position must be {row, col}");

        location_[0] = orientation; 
        location_[1] = position[0]; 
        location_[2] = position[1]; 

        return location_;
    }


    int orientation() const noexcept { return location_[0]; }
    int row()         const noexcept { return location_[1]; }
    int col()         const noexcept { return location_[2]; }

};

/**
 * Creation of the boat feet
 * @param fleetSize    [IN]
 * @param boatsLenght  [IN]
 * @param fleet        [OUT]
 */
void createFleet(int fleetSize, std::vector<int>& boatsLenght, std::vector<Boat>& fleet);