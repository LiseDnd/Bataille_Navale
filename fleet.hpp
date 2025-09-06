#pragma once
#include <vector>
#include <stdexcept>

class Boat {
    std::size_t size_;            
    std::vector<int> location_{3, 0}; 

public:
    explicit Boat(std::size_t size) : size_(size) {
        if (size_ == 0) throw std::invalid_argument("Boat size must be > 0");
    }

    std::size_t size() const noexcept { return size_; }
    
    std::vector<int> placement(int orientation, std::vector<int>& position){

        location_.emplace_back(static_cast<int>(orientation));
        location_.emplace_back(static_cast<int>(position[0]));
        location_.emplace_back(static_cast<int>(position[1]));
        
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