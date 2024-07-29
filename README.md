# Quadtree Generator
A program that can create a quadtree, create children including growing it uniformly by one layer and displays a graph of the resulting quadtree using gnuplot. Different tasks can be specified to create differing quadtrees and perform varying operations on them.

The maximum number of levels the tree can have can be limited to help limit the memory usage of the program.

A data-dependent tree can be generated where there are 3 data function choices available to compute on nodes and a tolerance level can be specified to determine when a leaf node can be requested to be split into child nodes.

## Tasks
- 1: make a non-uniform level 3 tree with a maximum of 5 levels
- 2: make a non-uniform level 3 tree with a maximum of 5 levels and grow the tree uniformly by one level
- 3: make a non-uniform level 3 tree with a maximum of 3 levels and grow the tree uniformly by one level
- 4: make a full uniform level 2 data-dependent tree with a maximum of 10 levels and tolerance of 0.2 and grow the tree using choice 1 data function

## Running the program
Compile the program by running `make` then execute it by running `./main`.
