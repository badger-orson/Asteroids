//
//  bigrock.h
//  asteroids
//
//  Created by Orson C Badger on 3/28/17.
//  Copyright © 2017 Orson C Badger. All rights reserved.
//

#ifndef bigrock_h
#define bigrock_h
#include "rocks.h"

/********************************************************************
 *This is the class of the Big Rock
 ********************************************************************/
class BigRock : public Rock
{
public:
    BigRock()
    {
        location.setX(random(-400, 400));
        
        location.setY(random(-400, 400));
        scoreValue = 1;
        
        //std::cout << "Location of BigRockX" << location.getX() << std::endl;
        //std::cout << "Location of BigRockY" << location.getY() << std::endl;

        
        //std::cout << "BigRock Constructor Called" << std::endl;
        // This is for testing to see if the velocity is 0, if so then it will
        // run random again and make the asteroid eventually have a velocity.
        while (velocity.getDy() == 0 && velocity.getDx() == 0)
        {
            velocity.setDy(random(-1,2));
            velocity.setDx(random(-1,2));
        }
		
    };
    
   void draw();
   virtual ~BigRock() {};
	int getRadius() {return BIG_ROCK_SIZE;};
};

#endif /* bigrock_h */
