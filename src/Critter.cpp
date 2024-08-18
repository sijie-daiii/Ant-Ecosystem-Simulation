#include "Critter.hpp"

// Constructor implementation
Critter::Critter(int x, int y) : x(x), y(y), moved(false), toBeRemoved(false) {}

// Destructor implementation
Critter::~Critter() {}

// Check if the critter should be removed
bool Critter::shouldRemove() const {
    return toBeRemoved;
}

// Check if the critter has moved
bool Critter::hasMoved() const {
    return moved;
}

// Set the moved status of the critter
void Critter::setMoved(bool val) {
    moved = val;
}

// Mark the critter for deletion
void Critter::markForDeletion() {
    toBeRemoved = true;
}

// Direction offsets for movement
std::pair<int, int> Critter::directionOffsets[8] = {
    {0, -1}, {1, -1}, {1, 0}, {1, 1},
    {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
};
