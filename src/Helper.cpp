#include "Helper.hpp"
#include "Ant.hpp"
#include <algorithm>
#include <random>

// Function to check for a nearby male ant
bool Helper::checkNearbyMale(std::vector<std::vector<Critter*>>& grid, int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            // Skip the current cell
            if (dx == 0 && dy == 0) continue;
            int checkX = x + dx;
            int checkY = y + dy;
            // Check if the coordinates are within grid bounds and not null
            if (checkX >= 0 && checkY >= 0 && checkX < grid.size() && checkY < grid[0].size() && grid[checkX][checkY] != nullptr) {
                // If a male ant is found, return true
                if (grid[checkX][checkY]->displaySymbol() == 'o') {
                    return true;
                }
            }
        }
    }
    // If no male ant is found, return false
    return false;
}

// Function to create offspring for a given critter
void Helper::createOffspring(std::vector<std::vector<Critter*>>& grid, int x, int y, int maxOffspring, std::default_random_engine& engine) {
    int offspringCount = 0;
    std::vector<std::pair<int, int>> breedingSpots;

    // Find all valid empty spots in the 16-neighborhood
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if (dx == 0 && dy == 0) continue; 
            int newX = x + dx;
            int newY = y + dy;
            // Check if the coordinates are within grid bounds and the cell is empty
            if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == nullptr) {
                breedingSpots.push_back(std::make_pair(newX, newY));
            }
        }
    }

    // Shuffle the breeding spots to randomize offspring placement
    std::shuffle(breedingSpots.begin(), breedingSpots.end(), engine);

    // Create new ants based on breeding proportions
    for (auto& spot : breedingSpots) {
        if (offspringCount >= maxOffspring) break; // Limit offspring to maxOffspring
        char offspringType;
        double randChoice = std::uniform_real_distribution<double>(0, 1)(engine);

        // Randomly decide the type of the offspring based on specified probabilities
        if (randChoice <= 0.005) {
            offspringType = '2';
        } else if (randChoice <= 0.6) {
            offspringType = 'W'; // Worker ant (60% chance)
        } else if (randChoice <= 0.7) {
            offspringType = 'o'; // Male ant (10% chance)
        } else {
            offspringType = 'Q'; // New queens with special breeding (less than 0.01%)
        }

        // Create the new ant and place it in the grid
        grid[spot.first][spot.second] = new Ant(spot.first, spot.second, offspringType, offspringType == 'Q' || offspringType == '2');
        offspringCount++;
    }
}

// Function to clean up the grid by removing critters marked for deletion
void Helper::cleanupGrid(std::vector<std::vector<Critter*>>& grid) {
    for (auto& row : grid) {
        for (auto& critter : row) {
            if (critter != nullptr && critter->shouldRemove()) {
                delete critter; // Delete the critter
                critter = nullptr;
            }
        }
    }
}
