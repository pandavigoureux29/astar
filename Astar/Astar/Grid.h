#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Image.hpp>

#include "Node.h"

class Grid
{

//Variables
private:
	std::vector<Node> m_gridData;
	int m_width = 10;
	int m_height = 10;
	int m_cellWidth = 64;
	int m_cellHeight = 64;

	Node * m_startingNode;
	Node * m_goalNode;

	sf::Font font;

public:
	static const int S_WALL_TYPE =  0;
	static const int S_GROUND_TYPE = 1;
	static const int S_START_TYPE = 2;
	static const int S_GOAL_TYPE = 3;

	void SetValueAt(int value, int i, int j);
	Node * GetNodeAt(int i, int j);

//functions
private:
	void FillStatic();
	void FillColumn(int index, int * arr);
	void FillRandom();

public :
	Grid();
	~Grid();
	Node * GetStartNode();
	Node * GetGoalNode();

	void Print();
	void Draw(sf::RenderWindow& _window) const;

	int GetWidth();
	int GetHeight();
};

