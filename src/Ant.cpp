#include "Ant.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Helper.hpp"

// Random engine initialized with system clock
std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());

Ant::Ant(int x, int y, char type, bool isQueen)
    : Critter(x, y), type(type), hasMated(false), timeSinceMating(0), timeSinceMove(0), isQueen(isQueen) {}

Ant::~Ant() {}

// Relocate function for Ant
void Ant::relocate(std::vector<std::vector<Critter*>>& grid) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(0, 7);

    int attempts = 0;
    while (attempts < 8) {
        auto dir = directionOffsets[distr(eng)];
        int newX = x + dir.first, newY = y + dir.second;

        // Check if new position is within bounds and empty
        if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == nullptr) {
            grid[x][y] = nullptr;
            grid[newX][newY] = this;
            x = newX;
            y = newY;
            break;
        }
        attempts++;
    }
    timeSinceMove++;
}

// Reproduce function for Ant
void Ant::reproduce(std::vector<std::vector<Critter*>>& grid) {
    if (!isQueen) return;  // Only queens can reproduce

    // Check for a nearby male ant to mate
    if (Helper::checkNearbyMale(grid, x, y)) {
        hasMated = true;
        std::cout << "Queen Ant has mated." << std::endl;
    }

    timeSinceMating++;

    // Breed if conditions are met
    if (timeSinceMating == 30 && hasMated) {
        Helper::createOffspring(grid, x, y, 10, engine);
    }

    if (timeSinceMating >= 90) {
        markForDeletion();
    }

    // Special case for cataglyphis
    if (type == '2' && timeSinceMating == 30) {
        reproduce(grid);
        hasMated = false;
    }
}

// Check if the ant should starve
void Ant::checkHunger(std::vector<std::vector<Critter*>>& grid) {
    if (isQueen) {
        if (timeSinceMating >= 90) {
            markForDeletion();
        }
    } else {
        if (timeSinceMove > 5) {
            markForDeletion();
        }
    }
    timeSinceMove++;
}

// Perform actions for each step
void Ant::performAction(std::vector<std::vector<Critter*>>& grid) {
    relocate(grid);
    reproduce(grid);
    checkHunger(grid);
    Helper::cleanupGrid(grid);  
}

// Return the symbol representing the ant
char Ant::displaySymbol() const {
    return type;
}
