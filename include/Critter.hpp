#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <vector>

// Base class Critter
class Critter {
public:
    Critter(int x, int y);  // Constructor
    virtual ~Critter();  // Virtual destructor

    // Pure virtual functions for derived classes
    virtual void relocate(std::vector<std::vector<Critter*>>& grid) = 0;
    virtual void reproduce(std::vector<std::vector<Critter*>>& grid) = 0;
    virtual void performAction(std::vector<std::vector<Critter*>>& grid) = 0;
    virtual char displaySymbol() const = 0;
    
    // Functions common to all critters
    bool shouldRemove() const;
    bool hasMoved() const;
    void setMoved(bool val);
    void markForDeletion();

protected:
    // Coordinates of the critter on the grid
    int x, y;  
    // Tracks if the critter has moved in the current timestep
    bool moved;  
    // Tracks if the critter should be removed
    bool toBeRemoved;  
    // Direction offsets for movement
    static std::pair<int, int> directionOffsets[8];  
};

#endif // CRITTER_HPP
