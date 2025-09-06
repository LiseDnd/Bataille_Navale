#pragma once
#include <vector>
#include <stdexcept>

class Boat {
    std::vector<int> location_;

public:
    explicit Boat(std::size_t size) {
        if (size == 0) throw std::invalid_argument("Boat size must be > 0");
        location_.resize(size);
    }

    std::size_t size() const noexcept { return location_.size(); }
};