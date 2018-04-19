//  bullet.cpp
//  Created by Orson C Badger on 2/27/17.
//  Copyright © 2017 Orson C Badger. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include "bullet.h"
#include "uiDraw.h"


/************************************************************************************
 * Bullet::fire()
 * This will fire a bullet
 ************************************************************************************/
void Bullet::fire(Point point, float angle, Velocity ship)
{
    location.setX(point.getX());
    location.setY(point.getY());
    float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
    float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
    velocity.setDx(dx + ship.getDx());
    velocity.setDy(dy + ship.getDy());
}

/************************************************************************************
 * Bullet::draw()
 *
 * This draws the bullet to the screen.
 ************************************************************************************/
void Bullet::draw()
{
    //std::cout << "LIFESPAN Before Function: " << lifespan << std::endl;
    if (lifespan == 40)
    {
        kill();
        lifespan = 0;
        
    }
    lifespan++;
    //std::cout << "LIFESPAN after running: " << lifespan << std::endl;
    drawDot(getPoint());
}
