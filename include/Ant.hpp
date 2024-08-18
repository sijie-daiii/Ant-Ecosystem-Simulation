#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include <vector>

// Ant class, derived from Critter
class Ant : public Critter {
public:
    Ant(int x, int y, char type, bool isQueen = false);  // Constructor
    virtual ~Ant() override;  // Destructor

    // Overridden virtual functions from Critter
    void relocate(std::vector<std::vector<Critter*>>& grid) override;
    void performAction(std::vector<std::vector<Critter*>>& grid) override;
    char displaySymbol() const override;
    void reproduce(std::vector<std::vector<Critter*>>& grid) override;
    void checkHunger(std::vector<std::vector<Critter*>>& grid);

private:
    // Type of ant ('Q', 'W', 'o', etc.)
    char type;  
    // Whether the queen ant has mated
    bool hasMated;  
    // Steps since mating
    int timeSinceMating;  
    // Steps since last move
    int timeSinceMove;  
    // Whether the ant is a queen
    bool isQueen;  
};

#endif // ANT_HPP
