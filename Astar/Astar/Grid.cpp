#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
	:m_gridData(10)
{
	//Create data
	for (int i = 0; i < m_gridData.size(); i++) {
		m_gridData[i] = std::vector<int>(10);
	}
	//FillRandom();
	FillStatic();
	Print();
}

void Grid::FillRandom() {
	//Set grounds and walls
	for (int i = 0; i < m_width; i++) {
		for (int j = 0; j < m_height; j++) {
			std::vector<int> *v = &m_gridData[i];
			//randomize type
			int randNumber = std::rand() % 10;
			printf("r%d ",randNumber);
			//Walls all around
			if (i == 0 || i == m_width - 1 || j == 0 || j == m_height - 1)
				randNumber = 9;
			// > 5 = Wall ; < 5 = Ground
			if (randNumber < 5) {
				SetValueAt( S_GROUND_TYPE, i, j);
			}
			else {
				SetValueAt( S_WALL_TYPE, i, j );
			}
		}		
	}
	//Set Start randomly, but at the edge
	int tempI=0, tempJ=0;
	tempI = std::rand() % 10 < 5 ? 0 : (m_width - 1);
	tempJ = std::rand() % 10 < 5 ? 0 : (m_height - 1);
	SetValueAt(S_START_TYPE, tempI, tempJ);
}

void Grid::SetValueAt(int _value, int _i, int _j) {
	std::vector<int> *v;
	if (_i < m_width) {
		v = &m_gridData[_i];
		if (_j < v->size()) {
			(*v)[_j] = _value;
		}
	}
	v = NULL;
}

int Grid::GetValueAt( int _i, int _j) {
	std::vector<int> *v;
	if (_i < m_width) {
		v = &m_gridData[_i];
		if (_j < v->size())
			return m_gridData[_i][_j];
	}
	v = NULL;
	return -1;
}

void Grid::Print() {
	for (int j = 0; j < m_height; j++) {
		for (int i = 0; i < m_width; i++) {
			printf("%d ", m_gridData[i][j]);
		}
		printf("\n");
	}
}

void Grid::Draw(sf::RenderWindow *_window) {
	//create rect template for the grid
	sf::RectangleShape rect;
	rect.setSize( sf::Vector2f(m_cellWidth, m_cellWidth) );

	//
	for (int j = 0; j < m_height; j++) {
		for (int i = 0; i < m_width; i++) {
			//get the type of the cell
			int type = m_gridData[i][j];
			//Colorize it
			switch (type) {
				case S_GROUND_TYPE: rect.setFillColor(sf::Color::White); break;
				case S_WALL_TYPE: rect.setFillColor(sf::Color::Black); break;
				case S_GOAL_TYPE: rect.setFillColor(sf::Color::Red); break;
				case S_START_TYPE: rect.setFillColor(sf::Color::Blue); break;
			}
			//set position 
			rect.setPosition(sf::Vector2f(i * 64, j * 64));
			//then finally draw
			_window->draw(rect);
		}
	}
}

void Grid::FillStatic() {
	m_gridData[0] = { 0,0,0,0,0,0,0,0,0,0 };
	m_gridData[1] = { 0,1,1,1,1,0,1,1,1,0 };
	m_gridData[2] = { 2,1,1,1,1,0,1,1,1,0 };
	m_gridData[3] = { 0,0,0,0,1,1,1,1,1,0 };
	m_gridData[4] = { 0,1,1,1,1,1,1,1,1,0 };
	m_gridData[5] = { 0,1,1,1,1,1,0,0,1,0 };
	m_gridData[6] = { 0,1,1,1,1,1,0,1,1,0 };
	m_gridData[7] = { 0,1,1,1,1,1,0,1,1,0 };
	m_gridData[8] = { 0,1,1,1,1,1,0,1,1,0 };
	m_gridData[9] = { 0,0,0,0,0,0,0,3,0,0 };
}

Grid::~Grid()
{
}
