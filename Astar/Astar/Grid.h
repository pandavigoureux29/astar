#pragma once

#include <SFML\Graphics.hpp>

class Grid
{

private:
	std::vector< std::vector<int> > m_gridData;

public:
	Grid();
	~Grid();
};

