# MAZE ESCAPE
## [EXAMINER'S ATTENTION]: source code are in the folder "My_SDL2_game_project"!
## TABLE OF CONTENTS
* [INTRO](#introduction)
* [STRUCTURE](#structure-and-techniques-used-inside)
* [HOW TO DOWNLOAD TO PLAY](#set-up)
* [PREVIEW](#preview)
* [MAIN FUNCTION](#main-function)
* [REFERENCES](#references)
* [WRAP UP](#conclusion)
* [LINKS](#related-links)

## INTRODUCTION
- Name: Nguyen Ba Hoang Long
- School: University of Engineering and Technology - Vietnam National University, Hanoi (VNU-UET)
- Student's ID: 23020680
- Big Project: MAZE ESCAPE (INT2215_52 - Advanced Programming AY 23-24)

## STRUCTURE AND TECHNIQUES USED INSIDE
- 6 classes dividied through header files and implement them through .cpp files. All of them would be used in main.cpp (divide files technique)
- Using basic data structures: vector, string, in-out file (fstream)
- Drawing maps through 2D-arrays (stored in .txt files), and also handle collision detection there.
- In main.cpp, I have declared variables of those classes, and then implement them based on the logic of the game.
### Game logic:
Firstly, user will see a menu. And then, if they press "Play" - they would go into their game. Otherwise, pressing "High score" would let them see the five recently high scores. If users win, they will be asked whether to continue or exit the game. If the former is true, a new map (and also new walls & roads) would be there to play. When the time is over, a "game over" screen would display.

## SET UP
- First, go to the Google Drive link in the section "LINKS"
- Download the .rar file (the name should be: My_SDL2_game_project.rar)
- Extract that .rar file by right clicking, choose "Extract Here" or "Extract to + file name"
- Click on the Debug folder (the Debug folder is in the same path as .vs folder). PAY ATTENTION: Not the Debug folder inside the My_SDL2_game_project folder
- Run the .exe file to play the game. Happy playing!

## PREVIEW
### MAIN MENU
- btw, NBHL is the acronym of my name :)
![main_menu](https://github.com/longnbh/maze-escape/assets/160746808/4698909e-35b5-4869-bdfc-dfcd376c1bec)
### HIGH SCORE SECTION
![high_score_section](https://github.com/longnbh/maze-escape/assets/160746808/7eeea1e6-a9f9-4c8f-b326-97390a273d22)
### PLAYER VIEW (1)
![player_view(1)](https://github.com/longnbh/maze-escape/assets/160746808/80f133c4-4e93-40eb-877b-395d9f13789f)
### PLAYER VIEW (2)
![player_view(2)](https://github.com/longnbh/maze-escape/assets/160746808/cabcaa07-eee3-4bc4-83c6-97c270292ae5)
### WIN SCREEN
![win_screen](https://github.com/longnbh/maze-escape/assets/160746808/ff9b1c9f-c8b0-438b-a631-43d6f436b24e)
### GAME OVER SCREEN
![game_over](https://github.com/longnbh/maze-escape/assets/160746808/70e9b70d-93ce-4fad-99c5-bc7dd30de276)

## MAIN FUNCTION
- Mission: pass the maze in a given number amount of time
- When playing, users could hear epic sounds & thrilling music, which make players motivated and arouse them to move faster
- The time is limited, so users need to figure out the labyrinths as soon as possible.
- Other function: 5 highest scores recently (code by the "vector" data structure)

## REFERENCES
### CODE IMPLEMENTATION
- SDL Wiki (https://wiki.libsdl.org/wiki/index): to know which functions implement the thing I want (load an audio, render an image, halt the music, etc)
- Learned how to write code in main.cpp from LazyFoo (https://lazyfoo.net/tutorials/SDL/) and some advice from my roomate
- Writing code almost on my own, arranging codes and drawing, etc by myself. That's why they are not "clean" at all...
- Assistance of fixing some bugs from AI-powered tools such as ChatGPT. Assistance of some techniques from our beloved mentor - Mr. Phan Anh Tu :3
### SOUNDS
- Pixabay.com and YouTube: all NoCopyright ('cause I appreciate artists' work of arts)
- Some trivial sound effects are gathered randomly from Internet
### GRAPHICS
- Mainly from itch.io: https://itch.io/game-assets
- Some buttons are collected from Google Images online.

## CONCLUSION
### WHAT I HAVE LEARNED THROUGH THIS PROJECT
- Logical thinking, writing code (not very clean though..) and building a whole project
- How to be creative in brainstorming ideas, adding vivid images and sounds from YouTube (and also show respect for their effort)
- Setting up linker settings and other libraries for my project
- Gaining valuable insights into SDL2: popular functions for loading sounds, rendering images and more than that!
- Learned how to get my code built structurally and neatly arranged, for smoother further maintenance and improvements.
- How to manage time effectively and also, overcome stresses when building a project, which is essential for my future career.
### FURTHER DEVELOPMENT THAT COULD BE IMPLEMENTED IN THE FUTURE
- Choose levels accordingly (easy, medium, difficult)
- Handle the movement of the player for smoother experience
- Adding threats and providing players with weapons and limit their lives in one single play

## Related links
- Executable file from Google Drive: https://drive.google.com/file/d/1pSxiiP2DaNlNJLbmxrhUGznNF9Oy025K/view?usp=sharing
