#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Image.hpp>

class Grid
{

//Variables
private:
	std::vector< std::vector<int> > m_gridData;
	int m_width = 10;
	int m_height = 10;
	int m_cellWidth = 64;
	int m_cellHeight = 64;

public:
	static const int S_WALL_TYPE =  0;
	static const int S_GROUND_TYPE = 1;
	static const int S_START_TYPE = 2;
	static const int S_GOAL_TYPE = 3;

//functions
private:
	void SetValueAt(int value,int i, int j);
	int GetValueAt(int i, int j);

	void FillStatic();
	void FillRandom();

public :
	Grid();
	~Grid();
	void Print();
	void Draw(sf::RenderWindow *_window);
};

