#include "Helper.hpp"
#include "Ecosystem.hpp"
#include <iostream>
#include <vector>
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <thread>

std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

Ecosystem::Ecosystem(int width, int height) : width(width), height(height) {
    // Initialize the simulation grid with nullptrs (empty grid)
    grid.resize(width, std::vector<Critter*>(height, nullptr));
}

void Ecosystem::initialize(int beetles, int queenAnts, int workerAnts, int maleAnts) {
    // Populate Doodlebugs
    addCreatures<Doodlebug>(beetles, 'D');

    // Populate Queen Ants 'Q'
    addCreatures<Ant>(queenAnts, 'Q');

    // Populate Worker Ants 'W'
    addCreatures<Ant>(workerAnts, 'W');

    // Populate Male Ants 'o'
    addCreatures<Ant>(maleAnts, 'o');
}

void Ecosystem::advanceStep() {
    // Process a single simulation step
    std::vector<Critter*> movedCreatures;

    // Move creatures
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            Critter* critter = grid[i][j];
            if (critter != nullptr && !critter->hasMoved()) {
                critter->relocate(grid);
                critter->setMoved(true);
                movedCreatures.push_back(critter);
            }
        }
    }

    // Reset moved state for all creatures
    for (Critter* critter : movedCreatures) {
        critter->setMoved(false);
    }

    // Process actions for all creatures
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            Critter* critter = grid[i][j];
            if (critter != nullptr) {
                critter->performAction(grid);
            }
        }
    }

    // Clean up removed creatures
    Helper::cleanupGrid(grid);
}

void Ecosystem::display() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[j][i] == nullptr) {
                std::cout << ".";
            } else {
                std::cout << grid[j][i]->displaySymbol();
            }
        }
        std::cout << "\n";
    }
}

template<typename T>
void Ecosystem::addCreatures(int count, char type) {
    std::uniform_int_distribution<int> distributionW(0, width - 1);
    std::uniform_int_distribution<int> distributionH(0, height - 1);
    int placed = 0;
    while (placed < count) {
        int randWidth = distributionW(generator);
        int randHeight = distributionH(generator);
        // If the cell is not occupied
        if (grid[randWidth][randHeight] == nullptr) {
            // Create the organism and place it on the grid
            if (typeid(T) == typeid(Doodlebug)) {
                grid[randWidth][randHeight] = new Doodlebug(randWidth, randHeight, 'D');
            } else if (typeid(T) == typeid(Ant)) {
                bool isQueen = (type == 'Q');
                grid[randWidth][randHeight] = new Ant(randWidth, randHeight, type, isQueen);
            }
            ++placed;
        }
    }
}

// Explicit template instantiation
template void Ecosystem::addCreatures<Doodlebug>(int count, char type);
template void Ecosystem::addCreatures<Ant>(int count, char type);
