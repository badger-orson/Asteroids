/*************************************************************
 * ship.h
 * Description: Defines a Rifle.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/
 #ifndef ship_h
 #define ship_h

#include "point.h"
#include "flyingObject.h"

#define SHIP_SIZE 10
#define ANGLE_START 90
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.2

class Ship : public FlyingObject
{
private:
   bool thrust;

   /**********************************************************
    * angle - The angle of the rifles in degrees.
    *  Assumes that straight right is 0 degrees and up is 90.
    **********************************************************/
   float angle;


public:
   Ship()
   {

     location.setX(0.0);
     location.setY(0.0);
     angle = 90;
     thrust = false;
     alive = true;
   }

   Ship(const Point & location) { angle = ANGLE_START; }

   /****************
    * Basic Getters
    ****************/
   float getAngle() const { return angle; }
   Point getPoint() const { return location; }

   /*****************
    * Drawing
    *****************/
   void draw();

   /*****************
    * Movement
    *****************/
   void moveLeft();
   void moveRight();
   void moveUp();
   void setThrust(bool thrust);
   float getThrust(){return THRUST_AMOUNT;}
   int getRadius() {return SHIP_SIZE;}
};

#endif /* ship_h */
