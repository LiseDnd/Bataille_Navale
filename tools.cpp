#include <cstdlib>

int randomInt(int min, int max) {
    return min + std::rand() % (max - min + 1);
}