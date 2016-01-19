#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "Spot.h"

using namespace std;
class Maze{
public:
    Maze();
    ~Maze();
    //get a spot at a position on the maze board
    //uses row and column
    Spot getSpotAt(int r, int c) const;
    //add spot to back of vector
    void addSpot(Spot);
    //will read and store the spotMaze
    bool readMaze(char* fileName);
    int getHeight();
    int getWidth();
    //return if a move can be made based on the
    //start and end points given
    bool canMove(int sX, int sY, int eX, int eY);
    int startX, startY, endX, endY;
private:
    int height, width;
    void destroy();
    //row and column maze stored in row column 1d vector
    vector<Spot> spotMaze;
};
#endif
