#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>
#include <fstream>
#include <sstream>

#ifndef GRID_HEIGHT
	#define GRID_HEIGHT 50
#endif

#ifndef GRID_WIDTH
	#define GRID_WIDTH 16
#endif

using namespace std;

//Object to handle drawing all the tiles into the game.
class TileManager {
private:
	int mapTileNum[GRID_HEIGHT][GRID_WIDTH];

public:
	vector<vector<Tile*>> tiles;

	//Constructor/Destructor
	TileManager();
	TileManager(string);
	~TileManager();

	//Functions
	void readMapFromFile(string);
	void setUpTiles();
};
