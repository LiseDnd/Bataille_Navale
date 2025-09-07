/**
 * Choose a random integer between min and max
 * @param min [IN]
 * @param max [IN]
 * 
 * @return int
 */
int randomInt(int min, int max);

/**
 * Asks the player for a cell to target and converts it to integers.
 * @param outRow [OUT]
 * @param outCol [OUT]
 * 
 * @return int
 */
bool readCoordinates(int& outRow, int& outCol);