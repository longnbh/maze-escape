#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <iostream>
#include <fstream>
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

class Map
{
public:
	Map() { ; }
	~Map() { ; }

	static const int(*getMazeMap())[MAP_WIDTH];

	void loadMap(const char* name);
	void drawMap(SDL_Renderer* renderer);

private:
	static int mazeMap[MAP_WIDTH][MAP_HEIGHT];
};

#endif