//
//  flyingObject.h
//  Skeet
//
//  Created by Orson C Badger on 2/27/17.
//  Copyright © 2017 Orson C Badger. All rights reserved.
//

#ifndef flyingObject_h
#define flyingObject_h

#include <iostream>
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"

class FlyingObject
{
public:
    FlyingObject()
    {
        location.setY(0.0);
        location.setX(0.0);
        alive = true;
        topLeft.setY(0);
        topLeft.setX(0);
        bottomRight.setY(0);
        bottomRight.setX(0);

    }

    void setScreenDimensions(Point topLeft, Point bottomRight)
    {
      //std::cout << "TopLeft " << topLeft << " bottomRight " << bottomRight << std::endl;
      this->topLeft = topLeft;
      topLeft = topLeft.getY() + 10;
      topLeft = topLeft.getX() + 10;
      this->bottomRight = bottomRight;
      bottomRight = bottomRight.getY() + 10;
      bottomRight = bottomRight.getX() + 10;
    }


    Velocity getVelocity() const {return velocity;};
    Point getPoint() const {return location;};
    bool isAlive() {return alive;};
    void setAlive(bool flag) {alive = flag;};
    void setVelocity(Velocity velocity);
    void setPoint(Point point) {location = point;};
    void kill();
    void advance();
    virtual void draw() = 0;  // This makes the class abstract. Allowing the game to never create a FLYOBJ.


protected:
    Point location;
    Velocity velocity;
    bool alive;
    Point topLeft;
    Point bottomRight;
};

#endif /* flyingObject_h */
