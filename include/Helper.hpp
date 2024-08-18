#ifndef HELPER_HPP
#define HELPER_HPP

#include "Critter.hpp"
#include <vector>
#include <random>

// Helper class for additional functionalities
class Helper {
public:
    static bool checkNearbyMale(std::vector<std::vector<Critter*>>& grid, int x, int y);
    static void createOffspring(std::vector<std::vector<Critter*>>& grid, int x, int y, int maxOffspring, std::default_random_engine& engine);
    static void cleanupGrid(std::vector<std::vector<Critter*>>& grid);
};

#endif // HELPER_HPP
