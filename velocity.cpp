/******************************************************************
* Class: Velocity
* Author
*  Orson C Badger
* Contains the methods for the Velocity class
******************************************************************/
#include "velocity.h"
#include <cmath>

/******************************************************************
* Velocity::setDx(float Dx):
* This sets a speed in a direction. X coordinate
******************************************************************/
void Velocity::setDx(float Dx)
{
   this-> Dx = Dx;
}

/******************************************************************
* Velocity::setDy(float Dy):
* This sets a speed in a direction. Y coordinate
******************************************************************/
void Velocity::setDy(float Dy)
{
   this-> Dy = Dy;
}

void Velocity::addDy(float Dy)
{
   this->Dy += Dy;
}

void Velocity::addDx(float Dx)
{
   this->Dx += Dx;

}

void Velocity::setVelocity(float angle , float speed)
{
  float dx = speed * (-cos(M_PI / 180.0 * angle));
  float dy = speed * (sin(M_PI / 180.0 * angle));
  setDx(dx);
  setDy(dy);
}
