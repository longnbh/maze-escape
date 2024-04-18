#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <cstdlib> //for rand() and srand()
#include<vector>
#include<ctime>
#include <iostream>
#include <fstream>
const int MAP_WIDTH = 15;
const int MAP_HEIGHT = 15;
const int numMap = 6, numRoad = 3;
const int CELL_SIZE = 40; //size of each cell in the maze;
const int numWall = 6;

class Map
{
public:
	Map()
	{
		/*srand(time(NULL));

		vector<string> imageFiles = { "img/wall1.png", "img/wall2.png" };
		int randIdx = rand() % imageFiles.size();
		path = imageFiles[randIdx];*/

	}
	~Map() { ; }

	static const int(*getMazeMap())[MAP_WIDTH];

	void loadMap(const char* name);
	void drawMap(SDL_Renderer* renderer, SDL_Texture* wallTexture, SDL_Texture* roadTexture);
	SDL_Texture* loadRandomMapAndWall(SDL_Renderer* renderer); //chon ngau nhien 1 map moi
	SDL_Texture* loadRandomRoad(SDL_Renderer* renderer);

private:
	static int mazeMap[MAP_WIDTH][MAP_HEIGHT];
	//string path;
};

#endif