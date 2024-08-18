# Ant Ecosystem Simulation
This project simulates an ant ecosystem where ants and doodlebugs interact within a grid environment. The simulation models the behavior of different types of ants, including queen ants, worker ants, and male ants, as they move, reproduce, and survive in their habitat.
![334](https://github.com/user-attachments/assets/e47252be-d693-458f-84be-dc4060aff0b6)


## Features

- **Ant Types:**
  - **Queen Ants ('Q'):** Can reproduce and create offspring, crucial for the survival of the ant colony.
  - **Worker Ants ('W'):** Perform tasks such as gathering resources and maintaining the colony.
  - **Male Ants ('o'):** Mate with queen ants to enable reproduction.
- **Doodlebugs ('D'):** Predators that hunt and eat ants, adding a survival challenge to the ecosystem.
- **Grid-Based Simulation:** The ecosystem operates on a 2D grid where ants and doodlebugs interact based on predefined rules.
- **Reproduction and Survival:** The simulation includes mechanisms for reproduction, starvation, and movement, creating a dynamic and challenging environment.

## Installation

To run this project, you'll need a C++ compiler. The project includes a `Makefile` to simplify the build process. Follow these steps to compile and run the simulation:

1. Clone the repository:
   ```bash
   git clone https://github.com/sijie-daiii/ant-ecosystem-simulation.git
   ```
2. Navigate to the project directory:
   ```bash
   cd ant-ecosystem-simulation
   ```
3. Compile the code using the `Makefile`:
   ```bash
   make
   ```
4. Run the simulation:
   ```bash
   ./main
   ```
5. Run the simulation:
   ```bash
   make clean
   ``` 


## Usage

After running the simulation, you'll be prompted to enter the initial number of doodlebugs, queen ants, worker ants, and male ants. The simulation will then proceed, showing the positions and actions of the critters on the grid. You can stop the simulation at any time by pressing 's' or 'q'.

## Project Structure

- **Ant.hpp/Ant.cpp:** Defines the `Ant` class, detailing the behavior and characteristics of various ant types.
- **Critter.hpp/Critter.cpp:** The base class for all critters, including common functionality like movement and reproduction.
- **Doodlebug.hpp/Doodlebug.cpp:** Defines the `Doodlebug` class, representing predators that interact with ants.
- **Ecosystem.hpp/Ecosystem.cpp:** Manages the simulation grid, handling the actions and interactions of critters in the ecosystem.
- **Helper.hpp/Helper.cpp:** Provides utility functions for tasks such as checking for nearby ants and cleaning up the grid.
- **main.cpp:** The entry point of the program, responsible for initializing and running the simulation.
- **Makefile:** Automates the build process for the project.

### UML
![2](https://github.com/user-attachments/assets/a9c8ec1f-4f46-4000-b5ee-88ec4f4ca6d2)


## Contributing

[sijie-daiii](https://github.com/sijie-daiii)

## License

This project is open-source and available under the MIT License.
