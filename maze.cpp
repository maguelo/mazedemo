#include "maze.hpp"
#include <iostream>
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::default_random_engine y std::random_device

using namespace std;

Maze::Maze(int rows, int cols)
{
    cout << "Maze test" << endl;
    this->rows = rows;
    this->cols = cols;

    cout << rows << " x " << cols << endl;
    this->maze = std::vector<std::vector<char>>(rows, std::vector<char>(cols, Maze::WALL));

    // Init the maze
    for (int y = 0; y < this->rows; y++)
    {
        for (int x = 0; x < this->cols; x++)
        {
            if ((x == 0) || (x == this->cols - 1) || (y == 0) || (y == this->rows - 1))
            { // Fill top or the bottom of the maze
                this->maze[y][x] = Maze::WALL;
            }
        }
    }
}

void Maze::generateMaze()
{
    this->beginning.x = 1;
    this->beginning.y = 1;
    this->backtrack(beginning.x, beginning.y);
}

void shuffleDirections(std::vector<std::pair<int, int>> &directions);

void Maze::backtrack(int x, int y)
{
    this->maze[y][x] = Maze::PATH;
    std::vector<std::pair<int, int>> directions;
    shuffleDirections(directions);

    for (const auto direction : directions)
    {
        int dx = direction.first;
        int dy = direction.second;

        // Calculate next neighbour
        int nx = x + dx;
        int ny = y + dy;

        // Check the neighbour is available
        if ((nx >= 0) && (nx < this->cols) && (ny >= 0) && (ny < this->rows))
            if ((0 <= nx < this->cols) && (0 <= ny < this->rows))
            {
                if (this->maze[ny][nx] == WALL)
                {

                    // Clean the path to achieve it
                    this->maze[ny - dy / 2][nx - dx / 2] = PATH;
                    this->backtrack(nx, ny);
                }
            }
    }
}

void shuffleDirections(std::vector<std::pair<int, int>> &directions)
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    directions.push_back({0, -2});
    directions.push_back({0, 2});
    directions.push_back({2, 0});
    directions.push_back({-2, 0});
    // std::vector<std::pair<int, int>> directions = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};

    std::shuffle(directions.begin(), directions.end(), rng);
}

std::ostream &operator<<(std::ostream &os, const Maze &maze)
{
    for (const auto &row : maze.maze)
    {
        for (const auto &cell : row)
        {
            os << cell << ' ';
        }
        os << std::endl;
    }
    return os;
}
