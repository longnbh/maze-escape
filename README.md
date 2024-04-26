# MAZE ESCAPE😵ꡙ‍ ꡌ‍ ꡚ‍😵
## [*ATTENTION FOR EXAMINERS*]: source code are in the folder "My_SDL2_game_project"!
## [*URLS*]: all referral links of my games (youtube demo vide, .zip files) are in the section 9 on the Table of Contents

## TABLE OF CONTENTS
* [1. INTRO OF MYSELF](#1-introduction)
* [2. STRUCTURES & TECHNIQUES](#2-structure-and-techniques-used-inside)
  * [Structure](#structure)
  * [Techniques](#techniques-used)
  * [Logic of the game](#game-logic) 
* [3. HOW TO DOWNLOAD MY GAME](#3-set-up)
  * [Method 1](#method-1)
  * [Method 2](#method-2)
* [4. HOW TO PLAY & EXIT GAME](#4-how-to-play)
  * [Moving](#moving)
  * [Mission](#main-mission)
* [5. PREVIEW](#5-preview)
* [6. MAIN FUNCTION](#6-main-function)
* [7. REFERENCES & DOCUMENTATIONS](#7-references)
  * [Code](#code-implementation)
  * [Sounds](#sounds)
  * [Graphics](#graphics)
* [8. WRAP UP](#8-conclusion)
  * [Key takeaways](#what-i-have-learned-through-this-project)
  * [Imperfections](#my-imperfections)
  * [Further improvements](#further-development-that-could-be-operated-in-the-future)
* [9. LINKS](#9-related-links)
  *[Executable](#executable-file-from-google-drive)
  *[Demo Video](#introduction-demo-video)
* [10. SPECIAL THANKS](#10-special-thanks)

## 1. INTRODUCTION
- **Name:** Nguyen Ba Hoang Long
- **School:** University of Engineering and Technology - Vietnam National University, Hanoi (VNU-UET)
- **Class:** QH-2023-I/CQ-J (K68J)
- **Student's ID:** 23020680
- **Big Project:** MAZE ESCAPE (INT2215_52 - Advanced Programming AY 23-24)

## 2. STRUCTURE AND TECHNIQUES USED INSIDE
### Structure
  - Main menu with 3 options: Play, Exit and High scores (to see 5 most recent highest scores)
  - After tapping Play, screen will jump on the main gameplay with a maze and one single character. Time given is 30 seconds.
  - If the player wins, a prompt will be available to ask them whether to continue or exit the game.
  - If the time is over, a "Game over" notification will be displayed and a button "Exit" to quit game :(
### Techniques used
  - Variables, loop (for with iterator, while) for game loop and others, control structure (if-else)
  - Files dividing techniques: 6 classes divided through declaration in header files and implementation through .cpp files. ALl of them would be used in main.cpp after all
  - Basic data structures: vector, string, in-out file (fstream), 2D arrays.
  - Class: constructor and destructor
  - Random numbers generator
  - Some basic functions in the library SDL, along with the use of various pointers
### Game logic:
Firstly, user will see a menu. And then, if they press "Play" - they would go into their game. Otherwise, pressing "High score" would let them see the five recently high scores. If users win, they will be asked whether to continue or exit the game. If the former is true, a new map (and also new walls & roads) would be there to play. When the time is over, a "game over" screen would display.

## 3. SET UP:
there are two methods that you could do to download to your PCs (up to you)
### Method 1:
- Step 1: go to the path in your computer that you want to put my project in. Example below is the folder Example:
![image](https://github.com/longnbh/maze-escape/assets/160746808/c98b8a96-aab0-42d0-8c25-9ac02535c173)
- Step 2: tap on the path above
![image](https://github.com/longnbh/maze-escape/assets/160746808/8f034b26-00bc-4cb8-99f4-0f2c0fa2c042)
- Step 3: type "cmd" and press Enter. A command prompt terminal would pop up. Clone this repo to your machine by typing:
```
git clone https://github.com/longnbh/maze-escape.git
```
- Step 4: you should see the folder "maze-escape" as below. Go to this folder until you see the folder Debug, click on the Debug folder
![image](https://github.com/longnbh/maze-escape/assets/160746808/230c9527-f890-4b70-ac45-8ac76746f7c3)
- Step 5: Run the .exe file and the program should run!
![image](https://github.com/longnbh/maze-escape/assets/160746808/d9da9530-863f-4dd5-842b-2cb2f1611c44)
### Method 2:
- Step 1: go to the Google Drive link in the section "9. LINKS" above
- Step 2: Download the .zip file (the name should be: My_SDL2_game_project.zip)
![image](https://github.com/longnbh/maze-escape/assets/160746808/66adf213-8ea6-4f3e-8e12-bcb7b237c71e)
- Step 3: Extract that .zip file by right clicking, choose "Extract Here" or "Extract to + file name" (winRAR using is preferable)
![image](https://github.com/longnbh/maze-escape/assets/160746808/f9aa820f-5628-4188-bda1-6e85a4cf68a8)
- Click on the Debug folder (the Debug folder is in the same path as .vs folder) - same as the up above method .
![image](https://github.com/longnbh/maze-escape/assets/160746808/bcfbe92c-4835-4b9e-871a-6c3c7d3e1940)
PAY ATTENTION: Not the Debug folder inside the My_SDL2_game_project folder
![image](https://github.com/longnbh/maze-escape/assets/160746808/9b19260d-7fc0-4e75-8c5b-175c20259fed)
- Run the .exe file in that Debug folder to play the game. Happy playing!

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
- SDL Wiki (https://wiki.libsdl.org/wiki/index): a documentation I have read thousand of times to know which functions implement the thing I want (load an audio, render an image, halt the music, etc)
- Learned how to arrange code in main.cpp from LazyFoo (https://lazyfoo.net/tutorials/SDL/) (and some little advice from my roomate)
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
### WHAT I HAVE LEARNED THROUGH THIS PROJECT: 
*Through two challenging months, I have experienced so much things to learn*
- Logical thinking, writing code by myself (not very clean though..) and building a whole project (which is executable) from the bottom
- I have broaden my knowledge about using Version Control system like Git, Git Bash and GitHub, which I have not known before!
- How to be creative in brainstorming ideas, adding vivid images and sounds from YouTube (and also show respect for their effort)
- Setting up linker settings and other libraries for my project
- Gaining valuable insights into SDL2: popular functions for loading sounds, rendering images and more than that!
- Learned how to get my code built structurally and neatly arranged, for smoother further maintenance and improvements.
- How to manage time effectively and also, overcome stresses when building a project, which is essential for my future career.
### MY IMPERFECTIONS:
- Some implementation files are lengthy, not clean at all
- Some functions are repeated because of they have not been synthesized into a single complete function for usage.
- Comments in my source code are hybrid: English & Vietnamese, which might cause some problems to be understandable to other developers who read my source.
### FURTHER DEVELOPMENT THAT COULD BE OPERATED IN THE FUTURE
#### 1. Choose levels accordingly (easy, medium, difficult)
- Each level will be a different maze based on its difficulty.
- High levels probably would be tougher to gain a victory
#### 2. Handle the movement of the player for smoother experience
#### 3. Adding threats and providing players with weapons and limit their lives in one single play
- Player might not only go straight to the destination, but also required to use weapons to overcome threats on their way.
- Some baits as: coins, traps would be likely to implement in my further improvement!
## 9. RELATED LINKS
### Executable file from Google Drive: 
https://drive.google.com/file/d/1Vap-BF0gg4-7VfT7YRuDd1ta9SGtpOGl/view?usp=sharing
### Introduction demo video: 
https://youtu.be/Un1mXo9wpGw
## 10. SPECIAL THANKS:
In the end, I want to show my gratitude for my parents, relatives, my roomates, friends and all helpful people around me for joining and helping me so much (both technically and mentally) in the process of finishing this project: from the smallest thing like ideas, advices to macroscopic ones as source code. I also value and feel grateful for the helpfulness from our teachers and our mentor for giving kindly constructive ideas and advices for me.
### Special thanks to these heroes:
- Mr. Le Duc Trong
- Mr. Tran Truong Thuy
- Mr. Phan Anh Tu - our kind mentor, who helped and gave me far more advice than I could ever imagine
- My roomates in dormitory and from K68J class
- And thanks to myself, for not ever giving up 😂

どうもありがとうございました🥰
# THANK YOU FOR TAKING THE TIME TO READ THIS CLUMSY README! I APPRECIATE YOUR ATTENTION TO THIS DOCUMENT! 🙏🙌
