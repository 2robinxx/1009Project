#include "TileManager.h"
#include <fstream>
#include <sstream>

TileManager::TileManager(){
	gridLength = 20;
	gridWidth = 16;
	readMapFromFile("Sprites/maps/map01.txt");
	setUpTiles();
}

void TileManager::setUpTiles() {
	int height = 0, width = 0;

	for (int i = 0; i < 50; i++) {

		vector<Tile*> row;
		for (int j = 0; j < 16; j++) {
			if (mapTileNum[i][j] == 0) {
				row.push_back(new Tile("Sprites/tiles/grass.png", width, height, false, false));
			}
			else if (mapTileNum[i][j] == 1) {
				row.push_back(new Tile("Sprites/tiles/wall.png", width, height, true, false));
			}
			else if (mapTileNum[i][j] == 2) {
				row.push_back(new Tile("Sprites/tiles/ice.png", width, height, true, true));
			}
			else if (mapTileNum[i][j] == 3) {
				row.push_back(new Tile("Sprites/tiles/snow.png", width, height, false, false));
			}
			else if (mapTileNum[i][j] == 4) {
				row.push_back(new Tile("Sprites/tiles/iceWall.png", width, height, true, false));
			}
			else if (mapTileNum[i][j] == 5) {
				row.push_back(new Tile("Sprites/tiles/wall-end.png", width, height, true, false));
			}
			else if (mapTileNum[i][j] == 6) {
				row.push_back(new Tile("Sprites/tiles/ice-end.png", width, height, true, false));
			}
			width += 48;
		}
		width = 0;
		height += 48;
		tiles.push_back(row);
	}
}

void TileManager::readMapFromFile(string map) {

	ifstream mapFile;
	mapFile.open(map);
	string line;
	int count = 0;
	int a, b = 0;

	while (getline(mapFile, line)) {
		istringstream iss(line);

		while (iss >> a) {
			if (a != ' ') {
				mapTileNum[count][b] = a;
				b++;
			}
		}
		count++;
		b = 0;
	}
}