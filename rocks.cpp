#include "rocks.h"

//
//  rock.cpp
//  Skeet
//
//  Created by Orson C Badger on 2/27/17.
//  Copyright © 2017 Orson C Badger. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "rocks.h"

using namespace std;

/************************************************************************************
 * rock::draw()
 * This will draw a rock in the Subclasses, Since rock is abstract everything below
 * needs to have a draw function.
 ************************************************************************************/
void Rock::draw()
{

}


/************************************************************************************
 * rock::draw()
 * This will draw a rock in the Subclasses, Since rock is abstract everything below
 * needs to have a draw function.
 ************************************************************************************/
void MediumRock::draw()
{
    rotation += MEDIUM_ROCK_SPIN;
    //cout << "Medium Asteroid is Spinning" << endl;
    drawMediumAsteroid(location, rotation);
}

/************************************************************************************
 * rock::draw()
 * This will draw a rock in the Subclasses, Since rock is abstract everything below
 * needs to have a draw function.
 ************************************************************************************/
void SmallRock::draw()
{
    rotation += SMALL_ROCK_SPIN;
    drawSmallAsteroid(location, rotation);
}
