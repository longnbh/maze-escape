#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <iostream>
#include <fstream>
const int MAP_WIDTH = 15;
const int MAP_HEIGHT = 15;

class Map
{
public:
	Map() 
	{ 
		/*srand(time(NULL));

			std::vector<std::string> imageFiles = { "img/wall1.png", "img/wall2.png" };
			int randIdx = rand() % imageFiles.size();
			path = imageFiles[randIdx];*/
	
	
	}
	~Map() { ; }

	static const int(*getMazeMap())[MAP_WIDTH];

	void loadMap(const char* name);
	void drawMap(SDL_Renderer* renderer);

private:
	static int mazeMap[MAP_WIDTH][MAP_HEIGHT];
	//std::string path;
};

#endif