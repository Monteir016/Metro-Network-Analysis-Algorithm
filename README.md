# Metro-Network-Analysis-Algorithm

## Overview

This project implements an algorithm to analyze a metro network and determine the maximum distance between connected metro lines. The program uses a graph-based approach to model the metro network and a modified BFS (Breadth-First Search) algorithm to compute the required values.

## Features

- **Graph Representation**: Models the metro network as a graph where stations are nodes and connections are edges.
- **Color Graph Construction**: Builds a secondary graph to represent connections between metro lines.
- **Modified BFS Algorithm**: Computes the maximum distance between connected metro lines.
- **Error Handling**: Detects and handles invalid input cases, such as disconnected stations or invalid configurations.

## Input Format

The program expects the following input format:

1. Three integers:
   - `numberStations` (`n`): The number of stations in the metro network.
   - `numberConnections` (`m`): The number of connections between stations.
   - `numberOfLines` (`l`): The number of metro lines.
2. `m` lines, each containing three integers:
   - `x` and `y`: The stations connected by the connection.
   - `line`: The metro line associated with the connection.

### Example Input
`5 6 3 1 2 1 2 3 1 3 4 2 4 5 2 1 5 3 2 4 3`

## Output Format

The program outputs:

1. `-1` if the metro network is invalid (e.g., disconnected stations or invalid configurations).
2. `0` if the metro network is valid but no connections between lines exist.
3. The maximum distance between connected metro lines if the network is valid.

### Example Output
`2`

## How It Works

1. **Input Reading**: The program reads the number of stations, connections, and metro lines, followed by the connections between stations.
2. **Metro Network Graph**: The metro network is represented as a graph where stations are nodes and connections are edges.
3. **Color Graph Construction**: A secondary graph is built to represent connections between metro lines.
4. **Modified BFS**: A BFS algorithm is used to compute the maximum distance between connected metro lines.
5. **Output**: The program outputs the result based on the analysis of the metro network.

## File Structure

- `Project2.cpp`: The main source code file containing all logic for input reading, graph construction, BFS traversal, and output generation.

## How to Build

To compile the project, use the following command:
`g++ -std=c++17 -o Project2 [Project2.cpp]`

This will generate an executable named Project2.

## How to Run
After building the project, run the executable and provide input as described above:
`./Project2 < input.txt`
Replace input.txt with the path to your input file.

### Example Usage
Input file (input.txt):
````
5 6 3
1 2 1
2 3 1
3 4 2
4 5 2
1 5 3
2 4 3
````
Run the program:
`./Project2 < input.txt`
Output:
`2`

## Dependencies
- C++17 or later
- Standard libraries: <iostream>, <vector>, <set>, <unordered_set>, <queue>

Author
Developed by Guilherme Monteiro. For more information, visit [my GitHub profile](https://github.com/Monteir016).
