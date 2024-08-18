#include "Doodlebug.hpp"
#include "Ant.hpp"
#include <algorithm>
#include <random>
#include <iostream>
#include "Helper.hpp"

Doodlebug::Doodlebug(int x, int y, char type)
    : Critter(x, y), stepsSinceLastMeal(0), stepsSinceLastReproduction(0) {}

Doodlebug::~Doodlebug() {}

// Relocate function for Doodlebug
void Doodlebug::relocate(std::vector<std::vector<Critter*>>& grid) {
    static const std::vector<std::pair<int, int>> directions = {
        {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 7);

    int directionIndex = dis(gen);
    bool moved = false;

    while (!moved) {
        int newX = x + directions[directionIndex].first;
        int newY = y + directions[directionIndex].second;

        // Check if new position is within bounds and empty
        if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size()) {
            if (grid[newX][newY] == nullptr) {
                grid[x][y] = nullptr;
                grid[newX][newY] = this;
                x = newX;
                y = newY;
                moved = true;
            } else if (dynamic_cast<Ant*>(grid[newX][newY])) {
                delete grid[newX][newY];
                grid[newX][newY] = this;
                grid[x][y] = nullptr;
                x = newX;
                y = newY;
                stepsSinceLastMeal = 0;
                moved = true;
            }
        }

        directionIndex = (directionIndex + 1) % 8;
    }

    stepsSinceLastMeal++;
}

// Reproduce function for Doodlebug
void Doodlebug::reproduce(std::vector<std::vector<Critter*>>& grid) {
    stepsSinceLastReproduction++;
    if (stepsSinceLastReproduction >= 10) {
        for (const auto& dir : directionOffsets) {
            int breedX = x + dir.first;
            int breedY = y + dir.second;
            if (breedX >= 0 && breedY >= 0 && breedX < grid.size() && breedY < grid[0].size() && grid[breedX][breedY] == nullptr) {
                grid[breedX][breedY] = new Doodlebug(breedX, breedY, 'D');
                stepsSinceLastReproduction = 0;
                return;
            }
        }
    }
}

// Check if the doodlebug should starve
void Doodlebug::checkHunger(std::vector<std::vector<Critter*>>& grid) {
    if (stepsSinceLastMeal >= 20) {
        std::cout << "Doodlebug at (" << x << ", " << y << ") has starved." << std::endl;
        markForDeletion();
    }
}

// Perform actions for each step
void Doodlebug::performAction(std::vector<std::vector<Critter*>>& grid) {
    relocate(grid);
    reproduce(grid);
    checkHunger(grid);
    Helper::cleanupGrid(grid);  
}

// Return the symbol representing the doodlebug
char Doodlebug::displaySymbol() const {
    return 'D';
}
