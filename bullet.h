//  bullet.h
//  Skeet
//
//  Created by Orson C Badger on 2/27/17.
//  Copyright © 2017 Orson C Badger. All rights reserved.
//

#ifndef bullet_h
#define bullet_h
#include "flyingObject.h"



#define BULLET_SPEED 15
#define BULLET_LIFE 40

class Bullet : public FlyingObject
{
public:
    Bullet()
    {
        alive = true;
        location.setX(0.0);
        location.setY(0.0);
        lifespan = 0;
    }

    void fire(Point point, float angle, Velocity ship);
    void draw();
    void advanceLifeSpan() { lifespan++; };
    int getLife() {return lifespan;};


private:
    int lifespan;

};

#endif /* bullet_h */
