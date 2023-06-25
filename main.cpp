#include <iostream>
#include "maze.hpp"

using namespace std;

int main()
{
    Maze maze = Maze(25,25);
  
    maze.generateMaze();

    std::cout << maze; 

}