#pragma once
#include "fleet.hpp"

/**
 * Choose a random integer between min and max
 * @param min [IN/OUT]
 * 
 */
void generateBoatPosition(Boat& boat);

/**
 * Place the boats on the game board.
 * @param fleetSize [IN]
 * @param fleet [IN]
 * @param grid [OUT]
 * 
 */
void generateFleetPlacement(int fleetSize, std::vector<Boat>& fleet, std::vector<std::vector<int>>& grid);