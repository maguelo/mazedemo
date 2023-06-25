#include <iostream>
#include <vector>
#include <string>

#include "maze.hpp"

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    Maze maze = Maze(5,11);
    std::cout << maze;  // Mostrar el contenido del laberinto
   
    maze.generateMaze();

    std::cout << maze;  // Mostrar el contenido del laberinto

}