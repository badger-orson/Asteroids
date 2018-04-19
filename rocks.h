#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock
#include <iostream>
#include "flyingObject.h"


/***********************************
 *This is the class of the Rock. this is astract.
 ***********************************/
class Rock : public FlyingObject
{
public:
    Rock() {};

    int getPointValue() {return scoreValue;};
    void setPointValue(int scoreValue) {scoreValue = scoreValue;};
    int hit();
    virtual void draw() = 0;
    virtual ~Rock() {};
    virtual int getRadius() = 0;

protected:
    int rotation;
    int scoreValue; // A rock has Points meaning a point values, everything else is inherited from the FlyingObject
};



/********************************************************************
 *This is the class of the Medium Rock
********************************************************************/
class MediumRock : public Rock
{
public:
    MediumRock()
    {
        location.setX(random(-400, 400));
        location.setY(random(-400,400));
        scoreValue = 4;

        // This is for testing to see if the velocity is 0, if so then it will
        // run random again and make the asteroid eventually have a velocity.
        while (velocity.getDy() == 0 && velocity.getDx() == 0)
        {
            velocity.setDy(random(-1,3));
            velocity.setDx(random(-1,3));
        }
    }
    MediumRock(Point point, Velocity velocity)
    {
        point = getPoint();
        velocity = getVelocity();
    }

    MediumRock(Point point)
    {
        point = getPoint();
    }

    void draw();
    int getRadius() {return MEDIUM_ROCK_SIZE;};
};


/********************************************************************
 *This is the class of the Small Rock
 *
 *
 *******************************************************************/
class SmallRock : public Rock
{
public:
    SmallRock()
    {
        location.setX(random(-400, 400));

        location.setY(random(-400,400));
        scoreValue = 10;


        // This is for testing to see if the velocity is 0, if so then it will
        // run random again and make the asteroid eventually have a velocity.
        while (velocity.getDy() == 0 && velocity.getDx() == 0)
        {
            velocity.setDy(random(-1,4));
            velocity.setDx(random(-1,4));
        }


    }

    void draw();
    int getRadius() {return SMALL_ROCK_SIZE;};
};

#endif /* rocks_h */
