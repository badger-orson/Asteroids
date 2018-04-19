###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Comeau, CS165
# Author:
#     Orson C Badger
# Summary:
#     This plays the game asteroids. It is fun to play
# Above and Beyond
#     I made the game bigger to add more of challenge to it.
#     I made the asteroids have different Point values.
#	  I added a score system to the screen and a level system
#     I added a Level system, it increments level at 10 points
#      there are 88 levels possible
#	  I made is so the game stopped drawing stuff when you died
#     I added the message game over to the middle of the screen when you fail
#     I added a message when you win the game.
# 	  I made it so the game starts with 15 asteroids,when you kill all of them you win.
# 	  I made the velocity of the ship 0.2, so it is slower and easier to control.
###############################################################


LFLAGS = -lglut -lGLU -lGL

##LDFLAGS= -framework GLUT -framework OpenGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o bigrock.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o bigrock.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

bigrock.o: bigrock.h rocks.h
	g++ -c bigrock.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
