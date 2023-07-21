# Color Block Order for MMU Calibration

This repository contains the source code and the development versions of the block color change algorithm that is used for color blocks in MMU Filament purge calibration print https://www.printables.com/model/531552-mmu-filament-purge-calibration-print


# Algorithm

Because a block will print as a gradient between the previous color and its color, to make all the gradients for a multi-material (filament) unit you need to put set colors in all combinations, but in a specific order. If if we the color as vertices of a oriented graph and gradients as the edges, the algorithm is a eulerian circuit that starts and ends with color 1.

For 2 colors:

    Gradient: 1 » 2. Block color: 2
    Gradient: 2 » 1. Block color: 1

For 3 colors:

    Gradient: 1 » 2. Block color: 2
    Gradient: 2 » 1. Block color: 1
    Gradient: 1 » 3. Block color: 3
    Gradient: 3 » 2. Block color: 2
    Gradient: 2 » 3. Block color: 3
    Gradient: 3 » 1. Block color: 1

For more color examples (4 and 5) check: https://www.printables.com/model/531552-mmu-filament-purge-calibration-print
    
# Build
g++ eulerianCircuit.cpp

# Usage

Run the binary în a console and enter the number of colors. The program will show the order of colors.
