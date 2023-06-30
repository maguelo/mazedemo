#include <iostream>
#include "maze.hpp"

using namespace std;

int main()
{
    Maze maze = Maze(6,6);
  
    maze.generateMaze();

    std::cout << maze; 

}