#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"
#include <vector>

// Doodlebug class, derived from Critter
class Doodlebug : public Critter {
public:
    Doodlebug(int x, int y, char type);  // Constructor
    virtual ~Doodlebug() override;  // Destructor

    // Overridden virtual functions from Critter
    void relocate(std::vector<std::vector<Critter*>>& grid) override;
    void performAction(std::vector<std::vector<Critter*>>& grid) override;
    char displaySymbol() const override;
    void reproduce(std::vector<std::vector<Critter*>>& grid) override;
    void checkHunger(std::vector<std::vector<Critter*>>& grid);

private:
    // Steps since last meal
    int stepsSinceLastMeal;  
    // Steps since last reproduction
    int stepsSinceLastReproduction;  
};

#endif // DOODLEBUG_HPP
