#include "TileManager.h"

//Constructors/Destructors
TileManager::TileManager(){
	readMapFromFile("Sprites/maps/map01.txt");
	setUpTiles();
}

TileManager::TileManager(string map) {
	readMapFromFile(map);
	setUpTiles();
}

TileManager::~TileManager() {
	cout << "TileManager destroyed." << endl;
}

//Functions
//Read the text file to know where to draw each individual tiles into the game.
void TileManager::readMapFromFile(string map) {
	ifstream mapFile;
	mapFile.open(map);
	string line;
	int count = 0;
	int a = 0, b = 0;

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

//Place all tiles into the vector according to their position in the game.
void TileManager::setUpTiles() {
	int height = 0, width = 0;

	for (int i = 0; i < GRID_HEIGHT; i++) {

		vector<Tile*> row;
		for (int j = 0; j < GRID_WIDTH; j++) {
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