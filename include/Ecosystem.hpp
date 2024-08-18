#ifndef ECOSYSTEM_HPP
#define ECOSYSTEM_HPP

#include "Critter.hpp"
#include <vector>

class Ecosystem {
public:
    // Constructor with parameters to set up the grid dimensions.
    Ecosystem(int width, int height); 
    // Populate the grid with organisms.
    void initialize(int beetles, int queenAnts, int workerAnts, int maleAnts);
    // Advance the simulation by one time step.
    void advanceStep(); 
    // Print the current state of the simulation grid.
    void display() const; 
    // Main loop to run the simulation (may not be needed with the new main loop).
    void runSimulation(int maxTimeSteps); 

private:
    // Dimensions of the simulation grid.
    int width, height;
    // 2D grid of pointer to Critter objects.
    std::vector<std::vector<Critter*>> grid; 

    // Template function to place organisms of a specific type on the grid.
    template<typename T>
    void addCreatures(int count, char type = '\0');
};

#endif // ECOSYSTEM_HPP
