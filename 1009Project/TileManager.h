#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

#ifndef TILEMANAGER
#define TILEMANAGER

using namespace std;

class TileManager {
public:

	vector<vector<Tile *>> tiles;
	int gridLength, gridWidth;
	int mapTileNum[50][16];
	
	TileManager();
	void setUpTiles();
	void readMapFromFile(string);
};

#endif
