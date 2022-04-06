#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>

class highscore
{
public:
	double highScores[10];
	void addFile();
	void addScore(double);
	void readScore();
	void writeScore();
};

