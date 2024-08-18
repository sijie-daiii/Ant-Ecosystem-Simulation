#include "Ecosystem.hpp"
#include <iostream>

// Function to check if the user wants to stop the simulation
bool userWantsToStop() {
    std::cout << "Press 's' or 'q' to stop the simulation or any other key to continue: ";
    char userInput;
    std::cin >> userInput;
    return userInput == 's' || userInput == 'q'; // Return true if 's' or 'q' was pressed
}

int main() {
    int width = 25;  // Width of the grid
    int height = 25; // Height of the grid
    int beetles, queenAnts, workerAnts, maleAnts;

    // Input the initial population counts
    std::cout << "Enter number of Doodlebugs: ";
    std::cin >> beetles;
    std::cout << "Enter number of Queen Ants: ";
    std::cin >> queenAnts;
    std::cout << "Enter number of Worker Ants: ";
    std::cin >> workerAnts;
    std::cout << "Enter number of Male Ants: ";
    std::cin >> maleAnts;

    // Create an ecosystem object
    Ecosystem ecosystem(width, height);
    // Populate the world with initial organisms
    ecosystem.initialize(beetles, queenAnts, workerAnts, maleAnts);

    // Run the simulation automatically with a timeout of 1000 time steps
    int maxTimeSteps = 1000; // Adjust this value if needed

    bool stopSimulation = false;
    int currentStep = 0;
    
    while (!stopSimulation && currentStep < maxTimeSteps) {
        ecosystem.advanceStep(); // Run one time step
        ecosystem.display(); // Print the grid state
        stopSimulation = userWantsToStop(); // Check if the user wants to stop
        currentStep++;
    }

    if (currentStep == maxTimeSteps) {
        std::cout << "Simulation reached maximum time steps. Exiting." << std::endl;
    } else {
        std::cout << "Simulation stopped by user or one species is eliminated." << std::endl;
    }

    return 0;
}
