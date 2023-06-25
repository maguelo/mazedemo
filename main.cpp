#include <iostream>
#include <vector>
#include <string>

#include "maze.hpp"

using namespace std;

int main()
{
    Maze maze = Maze(11,11);
  
    maze.generateMaze();

    std::cout << maze; 

}