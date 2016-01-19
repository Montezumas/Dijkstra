#ifndef SPOT_H
#define SPOT_H

class Spot{
public:
    Spot();
    //Constructor to set the movement possibilities
    Spot(bool, bool, bool, bool);
    ~Spot();
    bool getCanLeft();
    bool getCanUp();
    bool getCanRight();
    bool getCanDown();
private:
    //Booleans representing the possibility of a movement
    bool canLeft, canUp, canRight, canDown;
};

#endif
