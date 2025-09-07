#include "fleet.hpp"

/**
 * Informs of the effect of the action (Hit, sunk, water, already played)
 * @param fleet  [IN/OUT]
 * @param outRow [IN]
 * @param outCol [IN]
 * @param hit    [OUT]
 * 
 */
void targetResult(Fleet& fleet, int outRow, int outCol, int& hit);

/**
 * Displays game grid
 * @param fleet  [IN/OUT]
 * @param debug [IN]
 * 
 */
void printGrid(Fleet& fleet);