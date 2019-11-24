#### not so proud of what's done here tho, but at least it's honest work here ;_; 
# Jellal-s-Quest
## Summary
  The game is basically an endless runner game. A character named “Jellal”, a Japanese anime character runs through an open field while obstacles like ferocious Cactuses and Missiles come towards him. He must avoid the obstacles by Jumping or crouching. The game starts with 0 points and the score value automatically increases every 250ms. For every obstacle avoided, the player will get 10 points. No points will be decreased if you get hit by an obstacle. For every obstacle not avoided, the player loses 1 of his life. Initially player has 10 lives and 100 seconds time. The objective is just entertainment through a mini-game. Our goal was to learn the basics and gain experience of software development through our very first project.

## Project Modules:

 ### GlobalVars.h : 
  Contains all the global variables needed in all the functions and headers.
 ### Obstacle.h :
  Draws and drags the obstacles such as the cactuses and missiles. Also contains collision detection functions for all the obstacles.
 ### SkyAnimation.h :
  Contains the animation shown on the screen. Draws and animates clouds and flying birds randomly.
 ### ShowStatics.h :
  Contains the functions to show and control the Life, Score and Time on top of the screen.
 ### LoadGame.h :
  Contains the gameplay stat. structure (life, score, time left) and functions to load game which takes a parameter to determine if game is to be loaded from the saved file or the default values. 
 ### DrawGameStates.h :
  Contains all the functions that draws all the game states. Game States are main menu, game play screen, pause Menu, High Score screen, Settings menu, and about screen.
 ### GamePlayAnimation.h :
  Contains function that controls how to jump crouch slide and importantly run.

## Platform: 
  Microsoft Windows 10 used, XP or higher should support.
## Library: 
  iGraphics (a wrapper library for OpenGL) for the GUI and C++ for the main program.
## Tools Used: 
  Microsoft Visual Studio 2012 Community Edition.

## Limitaions:
  We could have taken the user’s name as input and store it in the highscore section. Background music and more sound effects could have been added. Due to limitations of the iGraphics
library images with Transparent Background could not have been added. This was our first desktop application project. We have gathered experience through this project. This project was made with iGraphics library, which has certain limitations. 

## Installation:
  Install Microsoft Visual Studio And Open the .sln file. 
### Visual Studio 2012: 
  Note that Visual Studio is a registered product of Microsoft. This is just a 30 day trial version. For further use, a user must buy a legal licence key to activate this product.
#### http://download.microsoft.com/download/1/F/5/1F519CC5-0B90-4EA3-8159-33BFB97EF4D9/VS2012_WDX_ENU.iso
###### If Anyone Wants to edit the source from the core and improve the game, then they are obviously open to do that. 
