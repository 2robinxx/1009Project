#pragma once


class highscore
{
public:
	double highScores[10];
	void addFile();
	void addScore(double);
	void readScore();
};

