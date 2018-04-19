//
//  flyingObject.cpp
//  Skeet
//
//  Created by Orson C Badger on 2/27/17.
//  Copyright © 2017 Orson C Badger. All rights reserved.
//

#include <stdio.h>
#include "flyingObject.h"


/************************************************************************************
* FlyingObject::Kill()
*
* This is to set the alive variable of a flying object to false and kill it.
************************************************************************************/
void FlyingObject::kill()
{
    setAlive(false);
}


/************************************************************************************
* FlyingObject::advance()
*
* This advances all of the flying objects on the screen.
* Making objects refresh the screen
************************************************************************************/
void FlyingObject::advance()
{
    location.addX(velocity.getDx());
    location.addY(velocity.getDy());

// This is the wrapping code right here.
    //std::cout << "Topleft:" << topLeft << "BottomRight: " << bottomRight << std::endl;
    if (location.getY() > topLeft.getY())
    {
      location.setY(topLeft.getX());
    }
    if (location.getY() < topLeft.getX())
    {
      location.setY(topLeft.getY());
    }
    if (location.getX() > bottomRight.getX())
    {
      location.setX(bottomRight.getY());
    }
    if (location.getX() < bottomRight.getY())
    {
      location.setX(bottomRight.getX());
    }

}

    void FlyingObject::setVelocity(Velocity velocity)
    {
      this->velocity = velocity;
    }
