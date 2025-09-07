#pragma once
#include "boat.hpp"

/**
 * Creation of the boat feet
 * @param fleetSize    [IN]
 * @param boatsLenght  [IN]
 * @param fleet        [OUT]
 */
void createFleet(int fleetSize, std::vector<int>& boatsLenght, std::vector<Boat>& fleet);

/**
 * Place the boats on the game board.
 * @param fleetSize [IN]
 * @param fleet [IN]
 * @param grid [OUT]
 * 
 */
void generateFleetPlacement(int fleetSize, std::vector<Boat>& fleet, std::vector<std::vector<int>>& grid);

class Fleet {
    /* Initialisation of the game board */
    std::vector<std::vector<int>> grid_; // Initialisation to 0 of a 10 by 10 grid
    std::vector<int> boatsLenght_; 
    std::vector<Boat> fleet_;

 public:
    Fleet() : grid_(10, std::vector<int>(10, 0)), boatsLenght_{5, 4, 3, 3, 2}
    {
        fleet_.reserve(boatsLenght_.size());
        createFleet(boatsLenght_.size(), boatsLenght_, fleet_);
    }

    void placeFleet() {
        generateFleetPlacement(static_cast<int>(fleet_.size()), fleet_, grid_);
    }

    std::vector<std::vector<int>>& grid() noexcept { return grid_; }

    std::vector<Boat>& fleet() noexcept { return fleet_; }

    const std::vector<int>& boatsLenght() const noexcept { return boatsLenght_; }
    int size() const noexcept { return static_cast<int>(fleet_.size()); }
};