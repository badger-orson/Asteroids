#include "ship.h"

/*************************************************************
 * File: ship.cpp
 *
 * Description: Contains the function bodies for the rifle class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "ship.h"
#include "point.h"
#include "uiDraw.h"

#include <cassert>
#include <iostream>
using namespace std;

void Ship :: draw()
{
   drawShip(location, 90 - angle, thrust);
}


void Ship::setThrust(bool thrust)
{
  this->thrust = thrust;
}

void Ship :: moveLeft()
{
  angle -= ROTATE_AMOUNT;
  //cout << "Angle Ship: " << angle << endl;
}


void Ship :: moveRight()
{
   angle += ROTATE_AMOUNT;
}

void Ship :: moveUp()
{
  float dx = THRUST_AMOUNT * (-cos(M_PI / 180.0 * angle));
  float dy = THRUST_AMOUNT * (sin(M_PI / 180.0 * angle));

  Velocity newVel = getVelocity();
  newVel.addDx(dx);
  newVel.addDy(dy);

  setVelocity(newVel);

  setThrust(true);
}
