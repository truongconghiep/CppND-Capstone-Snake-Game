# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0.8
  * Installation of SDL 2.0.10
    * wget https://www.libsdl.org/release/SDL2-2.0.10.tar.gz
    * tar -xzvf SDL2-2.0.10.tar.gz
    * cd SDL2-2.0.10
    * ./configure
    * make all
    * sudo make install
    
* SDL2_ttf
  * Installation instruction
    * wget  https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz
    * tar -xzvf SDL2_ttf-2.0.15.tar.gz
    * cd SDL2_ttf-2.0.15
    * ./configure
    * make all
    * sudo make install
    
  
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Added features

### General description

When the snake game starts, player will be asked to choose a game difficulty. After that a play window will pop-up with the snake and food. At the beginning the snake has 3 lives. The player must use keyboard to move the snake toward food. If the snake hit the food the player will receive a score, and another food will be created at another place in the playing window. If the snake hit any edge of the playing window or its body it will die and loses a live. If it has no live any more the game will be over.

### Play space is restricted in the game window.

If the snake hits any edge of the game window or its body it will die. After that if the snake still has lives the game will restart but it loses one live and player score will be reset.

### Game difficulty can be chosen by player

The difficulty of the game can be chosen by the player before the game start. At the beginning a small window will pop up with 3 buttons for three different levels. Player can click on a button to choose the difficulty he wants. Then this window will disappear and the main game window will pop-up. The speed of the snake will increase faster as the player chooses more difficult levels.

### Snake has more likes

The snake has 3 additional lives, that allows player continues playing after the snake dies. After every time the snake dies its lives is decreased. The game is only over when the snake has no live anymore. The player can see the number of lives on window title bar.

### Best score is recorded.

The best score is stored in a file after the game finishes. When the game starts the record will be read from the file and when the game finishes, if a new record is established, it will be write in the record file.


