#include "stdafx.h"
#include "Grid.h"

Grid::Grid()
	:m_gridData(10)
{
	for (int i = 0; i < m_gridData.size(); i++) {
		m_gridData[i] = std::vector<int>(10);
	}
}


Grid::~Grid()
{
}
