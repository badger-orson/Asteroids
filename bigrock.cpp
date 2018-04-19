//
//  bigrock.cpp
//  asteroids
//
//  Created by Orson C Badger on 3/28/17.
//  Copyright © 2017 Orson C Badger. All rights reserved.
//

#include <stdio.h>
#include "bigrock.h"
#include "rocks.h"

/************************************************************************************
 * rock::draw()
 * This will draw a rock in the Subclasses, Since rock is abstract everything below
 * needs to have a draw function.
 ************************************************************************************/
void BigRock::draw()
{
    rotation += BIG_ROCK_SPIN;
    drawLargeAsteroid(location, rotation);
}
