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

	int * m_startPoint;
	int * m_goalPoint;

	sf::Font font;

public:
	static const int S_WALL_TYPE =  0;
	static const int S_GROUND_TYPE = 1;
	static const int S_START_TYPE = 2;
	static const int S_GOAL_TYPE = 3;

	void SetValueAt(int value, int i, int j);
	int GetValueAt(int i, int j);

//functions
private:
	void FillStatic();
	void FillRandom();

public :
	Grid();
	~Grid();
	int * GetStartPoint();
	int * GetGoalPoint();

	void Print();
	void Draw(sf::RenderWindow *_window);

	int GetWidth();
	int GetHeight();
};

