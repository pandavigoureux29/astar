// Astar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "AstarExe.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 800), "Astar Pathfinding - C++");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	std::srand(time(0));

	Grid m_grid;
	AstarExe m_astarExe(&m_grid);
	m_astarExe.Start();

	int count = 0;

	while (window.isOpen())
	{
		//SFML Event for Window Closing
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				//Update Astar
				m_astarExe.Update();
			}
		}

		count++;

		/*if (count % 2 == 0) {
			m_astarExe->Update();
		}*/

		window.clear();
		//window.draw(shape);
		m_grid.Draw(window);
		window.display();
	}

    return 0;
}

