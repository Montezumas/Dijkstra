#include "Spot.h"

Spot::Spot(){
    canLeft = canUp = canRight = canDown = false;
}

Spot::Spot(bool left, bool up, bool right, bool down){
    canLeft = left;
    canUp = up;
    canRight = right;
    canDown = down;
}

bool Spot::getCanLeft(){
    return canLeft;
}

bool Spot::getCanUp(){
    return canUp;
}

bool Spot::getCanRight(){
    return canRight;
}

bool Spot::getCanDown(){
    return canDown;
}

Spot::~Spot(){

}
