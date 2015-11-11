#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
	:m_gridData(10)
{
	//Create data
	for (int i = 0; i < m_gridData.size(); i++) {
		m_gridData[i] = std::vector<int>(10);
	}
	FillRandom();
	Print();
}


void Grid::FillRandom() {
	for (int i = 0; i < m_width; i++) {
		for (int j = 0; j < m_height; j++) {
			std::vector<int> *v = &m_gridData[i];
			int randNumber = std::rand() % 10;
			if (randNumber < 5) {
				SetValueAt( S_GROUND_TYPE, i, j);
			}
			else {
				SetValueAt( S_WALL_TYPE, i, j );
			}
		}		
	}
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
			}
			//set position 
			rect.setPosition(sf::Vector2f(i * 64, j * 64));
			//then finally draw
			_window->draw(rect);
		}
	}
}

Grid::~Grid()
{
}
