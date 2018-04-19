/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/
#include <vector>
#include <list>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iostream>
#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rocks.h"
#include "bullet.h"
#include "rocks.h"
#include "bigrock.h"



using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{

   // Set up the initial conditions of the game
    score = 0;

   // TODO: Set your rock pointer to a good initial value (e.g., NULL)
   int score;
   level = 0;

   

   for (int i = 0; i < 15; i++)
   {
       createRock();
   }
   ship = new Ship;
   level = 0;
   
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceRock();
   advanceShip();
   handleCollisions();
   cleanUpZombies();
   level = score / 10;

}

/***************************************************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 **************************************************************************/
void Game :: advanceBullets()
{

   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i]->isAlive())
      {
         // this bullet is alive, so tell it to move forward
          //cout << "ADvancing BULLET"<< &bullets[i] << endl << endl;
         bullets[i]->advance();
      }
   }
}

/**************************************************************************
 * AdvanceShip
 * This function is going to create a rock and add it to my list.
 *
 ***************************************************************************/
void Game::advanceShip()
{
    ship->setScreenDimensions(topLeft, bottomRight);
    ship->advance();

  //cout << "Ship Advance: " << endl;
}

/**************************************************************************
* Create Rocks
* This function is going to create a rock and add it to my list.
*
***************************************************************************/
void Game::createRock()
{
        
        //cout << "Rock Created" << endl;
        Rock *rock = new BigRock();
        rock->setScreenDimensions(topLeft, bottomRight);
        rocks.push_back(rock);
        //cout << "Rock Added To List" << endl;


}

/**************************************************************************
 * GAME :: ADVANCE rock /// There is a problem here in the code.
 *
 * 1. If there is no rock, create one with some probability
 * 2. If there is a rock, and it's alive, advance it
 * 3. Check if the rock has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game::advanceRock()
{
    // we have a rock, make sure it's alive //
    for(list<Rock*> :: iterator iRock = rocks.begin(); (iRock != rocks.end()); iRock++)
    {
        if ((*iRock)->isAlive())
        {

            //cout << "Advance Rock: AdvanceRock() is called  " << endl;
            //cout << (*iRock)->getPoint() << "Get the Location of the iRock Advance Rock: " ;
            (*iRock)->advance();
            //cout << "Advance Rock: AdvanceRock() is finished  " << endl;
        }
     }
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game::isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a rock and a bullet.
 *************************************************************************/
void Game::handleCollisions()
{
for(list<Rock*> :: iterator iRock = rocks.begin(); (iRock != rocks.end()); iRock++)
{
    FlyingObject *newship = ship;
    FlyingObject *rock = (*iRock);
    Point point = (*iRock)->getPoint();
    Velocity vel = (*iRock)->getVelocity();
    int sizeOfRock = (*iRock)->getRadius();

    ship->setScreenDimensions(topLeft,bottomRight);

    // WE have to check if the ship hits a rock before it calcuates a bullet //
      if (getClosestDistance(ship,rock) < (*iRock)->getRadius() && ship->isAlive())
      {
         ship->kill();
         if (ship->isAlive())
         {
            //cout << "Ship is alive" << point << endl; // This is to test our ship is alive function;
         }
        
     
     }

   // now check for a hit (if it is close enough to any live bullets)
    for (vector<Bullet*> :: iterator iBullet = bullets.begin(); iBullet != bullets.end(); ++iBullet)
   {
      if ((*iBullet)->isAlive())
      {
         // this bullet is alive, see if its too close
         FlyingObject *bullet = (*iBullet); // Convert bullet to a FlyingObject

             // check if the rock is at this point (in case it was hit)
             if ((*iRock) != NULL && (*iBullet)->isAlive())
             {
                 // BTW, this logic could be more sophisiticated, but this will
                 // get the job done for now...
                 

                 if (getClosestDistance(rock, bullet) < (*iRock)->getRadius())
                 {

                     //change to make it so it depends on the rock. Different Health Value
                     if((*iRock)->isAlive() && (*iRock)->getRadius() == 4)
                     {
                        (*iBullet)->kill();
                        (*iRock)->kill();
                        score += (*iRock)->getPointValue();
                        splitRockForScreen(sizeOfRock, (*iRock));
                        
                        //cout << "GetRadius of rock = 4" << endl;
                     }
                    else if((*iRock)->isAlive() && (*iRock)->getRadius() == 8)
                    {
                        
                        (*iBullet)->kill();
                        (*iRock)->kill();
                        score += (*iRock)->getPointValue();
                        splitRockForScreen(sizeOfRock, (*iRock));
                        //cout << "GetRadius of rock = 8" << endl;
                    }
                    else if ((*iRock)->isAlive() && (*iRock)->getRadius()== 16)
                    {

                        (*iBullet)->kill();
                        (*iRock)->kill();
                        score += (*iRock)->getPointValue();
                        splitRockForScreen(sizeOfRock, (*iRock));
                        //cout << "GetRadius of rock = 16 " << point << vel.getDx() << ", " << vel.getDy() << endl;
                    }



                 }

             }
         }

      } // if bullet is alive

   } // for bullets
}

/**************************************************************************
 * GAME :: SPLITROCKFORCRYINGOUTLOUD!!!!!!!!()
 * This is make to split a rock when  it is hit by a bullet.
 **************************************************************************/
void Game::splitRockForScreen(int sizeOfRock , Rock * iRock)
{
    MediumRock * medRock;
    SmallRock * smallRock;
    Rock * newRocks;

    switch(sizeOfRock)
    {
        case 16:
            medRock = new MediumRock();
            medRock->setScreenDimensions(topLeft, bottomRight);
            medRock->getVelocity().setDx(iRock->getVelocity().getDx() + 1);
            medRock->getVelocity().setDy(iRock->getVelocity().getDy() + 1);
            medRock->setPoint(iRock->getPoint());
            newRocks = medRock;
            rocks.push_back(newRocks);
            
            if (medRock == NULL)
            {
                delete medRock;
                cout << "Deleted MedRock1 " << endl;
            }

            medRock = new MediumRock();
            medRock->setScreenDimensions(topLeft, bottomRight);
            medRock->getVelocity().setDx(iRock->getVelocity().getDx() - 1);
            medRock->getVelocity().setDy(iRock->getVelocity().getDy() - 1);
            medRock->setPoint(iRock->getPoint());
            newRocks = medRock;
            rocks.push_back(newRocks);

            if (medRock == NULL)
            {
                delete medRock;
                cout << "Deleted MedRock2 " << endl;
            }

            smallRock = new SmallRock();
            smallRock->setScreenDimensions(topLeft, bottomRight);
            smallRock->getVelocity().setDx(iRock->getVelocity().getDx() + 2);
            smallRock->getVelocity().setDy(iRock->getVelocity().getDy() + 2);
            smallRock->setPoint(iRock->getPoint());
            newRocks = smallRock;
            rocks.push_back(newRocks);     

            if (smallRock == NULL)
            {
                delete smallRock;
                cout << "Deleted SmallRock " << endl;
            }

            break;
        case 8:
            smallRock = new SmallRock();
            smallRock->setScreenDimensions(topLeft, bottomRight);
            smallRock->getVelocity().setDx(iRock->getVelocity().getDx() + 3);
            smallRock->getVelocity().setDy(iRock->getVelocity().getDy() + 3);
            smallRock->setPoint(iRock->getPoint());
            newRocks = smallRock;
            rocks.push_back(newRocks);    

            if (smallRock == NULL)
            {
                delete smallRock;
                cout << "Deleted SmallRock1 " << endl;
            }
        

            smallRock = new SmallRock();
            smallRock->setScreenDimensions(topLeft, bottomRight);
            smallRock->getVelocity().setDx(iRock->getVelocity().getDx() - 3);
            smallRock->getVelocity().setDy(iRock->getVelocity().getDy() - 3);
            smallRock->setPoint(iRock->getPoint());
            newRocks = smallRock;
            rocks.push_back(newRocks);    

            if (smallRock == NULL)
            {
                delete smallRock;
                cout << "Deleted SmallRock2 " << endl;
            }
        
            break;
    }
    
    
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate rock)
 **************************************************************************/
void Game :: cleanUpZombies()
{
    // Look for dead bullets
    vector<Bullet*>::iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end())
    {
        Bullet *bullet = *bulletIt;
        // Asteroids Hint:
        // If we had a list of pointers, we would need this line instead:
        //Bullet* pBullet = *bulletIt;

        if (!bullet->isAlive())
        {
            // If we had a list of pointers, we would need to delete the memory here...

            // remove from list and advance
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++; // advance
        }

    }

// This will go through and delete the rocks after erasing them from the  list //

        list<Rock*>::iterator iRock = rocks.begin();
        while(iRock != rocks.end())
        {
            Rock * pRock = *iRock;

            if (!(*iRock)->isAlive())
            {
                iRock = rocks.erase(iRock);

                if (*iRock == NULL)
                {
                    delete (*iRock);
                }
            }
            else
            {
                iRock++; //advance the rock
            }
        }
}


/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
 {
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      ship->moveLeft();
   }

   if (ui.isRight())
   {
      ship->moveRight();
   }

   if (ui.isUp())
   {
     ship->moveUp();
   }
   else
   {
     ship->setThrust(false);
   }

   // Check for "Spacebar
   if (ui.isSpace())
   {
      Bullet *newBullet = new Bullet;
      newBullet->setScreenDimensions(topLeft, bottomRight);
      newBullet->fire(ship->getPoint(), ship->getAngle(), ship->getVelocity());

      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // Draw The Asteroids to the screen, if they are Alive //

   // draw the bullets, if they are alive //

   // drawShip //
    if (ship->isAlive())
    {
        for (list<Rock*> :: iterator iRock = rocks.begin(); iRock != rocks.end(); iRock++)
        {
            //cout << (*iRock)->getPoint() << "Get the Location of the iRock Draw Rock: " ;
            if ((*iRock)->isAlive())
            {
                if ((*iRock)->getRadius() == 4 && (*iRock)->isAlive())
                {
                    (*iRock)->draw();
                }
                else
                {
                    (*iRock)->draw();
                }

                //cout << "Game::Draw Called is alive and ->Draw()" << endl;
            }

        }

        ship->draw();
        for (int i = 0; i < bullets.size(); i++)
        {
            if (bullets[i]->isAlive())
            {
                if (ship->isAlive())
                {
                    ship->draw();
                }
                bullets[i]->draw();
                //cout << "DRAW BULLET: " << &bullets[i] << endl << endl << endl;
            }
        }
        
        //if the rocks are all dead then we are able to level up.
        if (rocks.empty())
        {

                Point gameoverMessage;
                gameoverMessage.setX(-85);
                gameoverMessage.setY(0);
                drawText(gameoverMessage, "YOU WON!!! How did you Win!?? ");
            //level++;
        }
        

}
    else
    {
        Point gameoverMessage;
        gameoverMessage.setX(-45);
        gameoverMessage.setY(0);
        drawText(gameoverMessage, "Game Over DUDE!!!");
        
        if (ship == NULL)
        {
            delete ship;
        }
        //cout << "DRAW SHIP = FAILED" << endl;
    }

   // Put the score on the screen //



   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   drawNumber(scoreLocation, score);

   Point levelLocation;
   levelLocation.setX(topLeft.getX() + 15);
   levelLocation.setY(topLeft.getY() - 770);
   drawNumber(levelLocation, level);

   Point levelMessage;
   levelMessage.setX(-390);
   levelMessage.setY(-360);
   drawText(levelMessage, "Level: ");
}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const FlyingObject *obj1, const FlyingObject *obj2) const
{
   // find the maximum distance traveled
    //cout << "ITS a HIT Get Closest Distance:::::: !!!" << endl;
   float dMax = max(abs(obj1->getVelocity().getDx()), abs(obj1->getVelocity().getDy()));
   dMax = max(dMax, abs(obj2->getVelocity().getDx()));
   dMax = max(dMax, abs(obj2->getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1->getPoint().getX() + (obj1->getVelocity().getDx() * i / dMax),
                     obj1->getPoint().getY() + (obj1->getVelocity().getDy() * i / dMax));
      Point point2(obj2->getPoint().getX() + (obj2->getVelocity().getDx() * i / dMax),
                     obj2->getPoint().getY() + (obj2->getVelocity().getDy() * i / dMax));

      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();

      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

      distMin = min(distMin, distSquared);
   }

   return sqrt(distMin);
}
