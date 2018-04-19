/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
#include "rocks.h"
#include "bullet.h"



using namespace std;
#define CLOSE_ENOUGH 15


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();

   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);

   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();

   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
    float getClosestDistance(const FlyingObject *obj1, const FlyingObject *obj2) const;

private:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;

   int score;
   int level;

   list<Rock*> rocks;
   Ship * ship;
   vector<Bullet*> bullets;


   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceShip();
   void advanceBullets();
   void advanceRock();
   void createRock();
   void handleCollisions();
   void cleanUpZombies();
   void splitRockForScreen(int sizeOfRock, Rock * iRock);
   void mediumExplosion();
   void smallExplosion();
   int getScore(){return score;};
   void setScore(int score) {this->score = score;};
   int getLevel() {return level;};
   void setlevel(int level, int score)
   {
       this->level = level;
       this->score = score;
       if (score % 10 == 0)
       {
            //cout << "level is supposed to be incrementing";
            level++;
       }
   };

};

#endif /* GAME_H */
