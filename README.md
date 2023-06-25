# mazedemo

Recursive implementation https://en.wikipedia.org/wiki/Maze_generation_algorithm

The depth-first search algorithm of maze generation is frequently implemented using backtracking. This can be described with a following recursive routine:

*  Given a current cell as a parameter
* Mark the current cell as visited
* While the current cell has any unvisited neighbour cells

      * Choose one of the unvisited neighbours
      * Remove the wall between the current cell and the chosen cell
      * Invoke the routine recursively for the chosen cell

which is invoked once for any initial cell in the area.


To build the project:

1. git clone git@github.com:maguelo/mazedemo.git
2. cd mazedemo
3. mkdir build
4. cd build
5. cmake ..
6. make
7. ./MazeProject
