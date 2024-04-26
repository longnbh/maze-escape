# MAZE ESCAPE😵ꡙ‍ ꡌ‍ ꡚ‍😵
## [EXAMINER'S ATTENTION]: source code are in the folder "My_SDL2_game_project"!
## [LINK ATTENTION]: all referral links of my games are in the section 9 

## TABLE OF CONTENTS
* [1. INTRO](#1-introduction)
* [2. STRUCTURE](#2-structure-and-techniques-used-inside)
* [3. HOW TO DOWNLOAD TO PLAY](#3-set-up)
* [4. HOW TO PLAY & EXIT GAME](#4-how-to-play)
* [5. PREVIEW](#5-preview)
* [6. MAIN FUNCTION](#6-main-function)
* [7. REFERENCES](#7-references)
* [8. WRAP UP](#8-conclusion)
* [9. LINKS](#9-related-links)
* [10. SPECIAL THANKS](#10-special-thanks)

## 1. INTRODUCTION
- **Name:** Nguyen Ba Hoang Long
- **School:** University of Engineering and Technology - Vietnam National University, Hanoi (VNU-UET)
- **Class:** QH-2023-I/CQ-J (K68J)
- **Student's ID:** 23020680
- **Big Project:** MAZE ESCAPE (INT2215_52 - Advanced Programming AY 23-24)

## 2. STRUCTURE AND TECHNIQUES USED INSIDE
- Structure
  - Main menu with 3 options: Play, Exit and High scores (to see 5 most recent highest scores)
  - After tapping Play, screen will jump on the main gameplay with a maze and one single character. Time given is 30 seconds.
  - If the player wins, a prompt will be available to ask them whether to continue or exit the game.
  - If the time is over, a "Game over" notification will be displayed and a button "Exit" to quit game :(
- Techniques used
  - Variables, loop (for with iterator, while) for game loop and others, control structure (if-else)
  - Files dividing techniques: 6 classes divided through declaration in header files and implementation through .cpp files. ALl of them would be used in main.cpp after all
  - Basic data structures: vector, string, in-out file (fstream), 2D arrays.
  - Class: constructor and destructor
  - Random numbers generator
  - Some basic functions in the library SDL, along with the use of various pointers
### Game logic:
Firstly, user will see a menu. And then, if they press "Play" - they would go into their game. Otherwise, pressing "High score" would let them see the five recently high scores. If users win, they will be asked whether to continue or exit the game. If the former is true, a new map (and also new walls & roads) would be there to play. When the time is over, a "game over" screen would display.

## 3. SET UP
- First, go to the Google Drive link in the section "LINKS"
- Download the .rar file (the name should be: My_SDL2_game_project.rar)
- Extract that .rar file by right clicking, choose "Extract Here" or "Extract to + file name"
- Click on the Debug folder (the Debug folder is in the same path as .vs folder). PAY ATTENTION: Not the Debug folder inside the My_SDL2_game_project folder
- Run the .exe file to play the game. Happy playing!

## 4. HOW TO PLAY
### Moving
|   KEYS   |    FUNCTION   |
|:--------:|:-------------:|
|     ↑    |       UP      |
|     ↓    |      DOWN     |
|     ←    |      LEFT     |
|     →    |     RIGHT     |
|     Esc  |    Exit game  |
### Main mission:
the target is very simple: go to the destined place (dart shaped) from the beginning before the time's over.

## 5. PREVIEW
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

## 6. MAIN FUNCTION
- Hovering the character throughout the labyrinth, the character would bump into the walls if they come near to those walls.
- When playing, users could hear epic sounds & thrilling music, which make players motivated and arouse them to move faster
- The time is limited, so players need to figure out the labyrinths as soon as possible, which is pretty strained for them
- Other function: 5 highest scores recently (code by the "vector" data structure)

## 7. REFERENCES
### CODE IMPLEMENTATION
- Writing code almost on my own, arranging codes and drawing, etc by myself. That's why they are not "clean" at all...
- SDL Wiki (https://wiki.libsdl.org/wiki/index): to know which functions implement the thing I want (load an audio, render an image, halt the music, etc)
- Learned how to write code in main.cpp from LazyFoo (https://lazyfoo.net/tutorials/SDL/) and some advice from my roomate
- Assistance of fixing some bugs from AI-powered tools such as ChatGPT. Assistance of some techniques from our beloved mentor - Mr. Phan Anh Tu :3
### SOUNDS
- https://pixabay.com/
- NoCopyrightSounds from YouTube
- Some trivial sound effects are gathered randomly from Internet
### GRAPHICS
- Software used to create maps: Tiled and aseprite to edit them.
- Website to create maze: https://www.mazegenerator.net/
- Characters, roads and walls: https://itch.io/game-assets
- UI and Menu: https://www.shutterstock.com/
- Some buttons are collected from Google Images online.

## 8. CONCLUSION
### WHAT I HAVE LEARNED THROUGH THIS PROJECT: through two challenging months, I have experienced so much things to learn
- Logical thinking, writing code by myself (not very clean though..) and building a whole project (which is executable) from the bottom
- I have broaden my knowledge about using Version Control system like Git, Git Bash and GitHub, which I have not known before!
- How to be creative in brainstorming ideas, adding vivid images and sounds from YouTube (and also show respect for their effort)
- Setting up linker settings and other libraries for my project
- Gaining valuable insights into SDL2: popular functions for loading sounds, rendering images and more than that!
- Learned how to get my code built structurally and neatly arranged, for smoother further maintenance and improvements.
- How to manage time effectively and also, overcome stresses when building a project, which is essential for my future career.
### IMPERFECTIONS:
- Some implementation files are lengthy, not clean at all
- Some functions are repeated because of they have not been synthesized into a single complete function for usage.
- Comments in my source code are hybrid: English & Vietnamese, which might cause some problems to be understandable to other developers who read my source.
### FURTHER DEVELOPMENT THAT COULD BE IMPLEMENTED IN THE FUTURE
#### 1. Choose levels accordingly (easy, medium, difficult)
- Each level will be a different maze based on its difficulty.
- High levels probably would be tougher to gain a victory
#### 2. Handle the movement of the player for smoother experience
#### 3. Adding threats and providing players with weapons and limit their lives in one single play
- Player might not only go straight to the destination, but also required to use weapons to overcome threats on their way.
- Some baits as: coins, traps would be likely to implement in my further improvement!
## 9. RELATED LINKS
- Executable file from Google Drive: https://drive.google.com/file/d/1pSxiiP2DaNlNJLbmxrhUGznNF9Oy025K/view?usp=sharing
- Introduction video:
## 10. SPECIAL THANKS:
In the end, I want to show my gratitude for my parents, relatives, my roomates, friends and all helpful people around me for joining and helping me so much in the process of finishing this project: from the smallest thing like ideas, advices to macroscopic ones as source code. I also value and feel grateful for the helpfulness from our teachers and our mentor for giving kindly constructive ideas and advices for me.
### Special thanks to these heroes:
- Mr. Le Duc Trong
- Mr. Tran Truong Thuy
- Mr. Phan Anh Tu - our kind mentor, who helped and gave me so much advice that I could ever imagine
- My roomates in dormitory and from K68J class

どうもありがとうございました🥰
# THANK YOU FOR READING THIS SMALL PIECE OF CLUMSY README! I APPRECIATE YOUR PRECIOUS TIME TO READ UNTIL NOW! 🙏🙌
