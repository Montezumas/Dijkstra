#include "Maze.h"

Maze::Maze(){
    height = width = startX = startY = endX = endY = 0;
}

Maze::~Maze(){
    
}


Spot Maze::getSpotAt(int r, int c) const{
    return spotMaze[(r * width) + c];
}

void Maze::destroy(){
    width = height = startX = startY = endX = endY = 0;
    if(!spotMaze.empty()){
        spotMaze.clear();
    }
}

void Maze::addSpot(Spot spot){
    spotMaze.push_back(spot);
}

int Maze::getHeight(){
    return height;
}

int Maze::getWidth(){
    return width;
}

bool Maze::readMaze(char* fileName){
    ifstream myFile;
    myFile.open(fileName, ifstream::in);

    if (!myFile.is_open()){
        return false;
    }

    int w, h, sX, sY, eX, eY;
    myFile >> h;
    myFile >> w;
    myFile >> sY;
    myFile >> sX;
    myFile >> eY;
    myFile >> eX;

    height = h;
    width = w;
    startX = sX;
    startY = sY;
    endX = eX;
    endY = eY;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int spotInt;
            myFile >> spotInt;
        
            Spot tempSpot(!(spotInt & 8), !(spotInt & 4), !(spotInt & 2), !(spotInt & 1));
            addSpot(tempSpot);
        } 
    }  

    return true;  
}

bool Maze::canMove(int sX, int sY, int eX, int eY){
    int difX = sX - eX;
    int difY = sY - eY;
    bool flag = false;
    
    if(sX < 0 || sX > height - 1 || sY < 0 || sY > width - 1 || eX < 0 || eX > height - 1 || eY < 0 || eY > width - 1){
        return flag;
    } else if(abs(difX) == 1 && abs(difY) == 1){
        return flag;
    } else if(difX == 1 && difY == 0 && getSpotAt(sX, sY).getCanUp()){
        //up
        flag = true;
    } else if(difX == (-1) && difY == 0 && getSpotAt(sX, sY).getCanDown()){
        //down
        flag = true;
    } else if(difY == 1 && difX == 0 && getSpotAt(sX, sY).getCanLeft()){
        //left
        flag = true;
    } else if(difY == (-1) && difX == 0 && getSpotAt(sX, sY).getCanRight()){
        //right
        flag = true;
    } else{

    }

    return flag;

}
