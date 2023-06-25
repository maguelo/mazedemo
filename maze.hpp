#include <vector>
#include <iostream>
#include <random>
struct Point
{
    int x, y;
};

class Maze {      

  public:
    const char PATH= ' ';
    const char WALL= 'x';
    const char BEGINNING = 'B';
    const char END = 'E';

    Maze(int rows, int cols);
    void generateMaze();
    friend std::ostream& operator<<(std::ostream& os, const Maze& maze);

  private:
    void backtrack(int x, int y);
    void setGoals();
    void generateRandomPosition(Point &candidate);

  private:
    int rows;
    int cols;   
    Point beginning;  
    Point end;   
    std::vector<std::vector<char>> maze;
};