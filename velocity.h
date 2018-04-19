/***********************************************************************
 * Header File:
 *    LANDER : A class representing the lunar LANDER
 * Author:
 *    Orson C Badger
 * Summary:
 *    Contains info about the Lunar Lander class
 ************************************************************************/

 #ifndef VEL_H
 #define VEL_H
class Velocity

{
private:
   float Dx;
   float Dy;



public:
   Velocity()
   {
      Dx = 0;
      Dy = 0;

      setDx(Dx);
      setDy(Dy);
   }

    Velocity(float Dx, float Dy) {this->Dx = Dx; this->Dy = Dy;}

   float getDx() { return Dx;};
   float getDy() { return Dy;};

   void addDy(float Dy);
   void addDx(float Dx);
   void setDx(float Dx);
   void setDy(float Dy);
   void setVelocity(float angle, float speed);

};


#endif
