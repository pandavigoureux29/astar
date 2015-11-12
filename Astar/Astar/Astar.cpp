// Astar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "AstarExe.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	std::srand(time(0));

	Grid * m_grid = new Grid();
	AstarExe * m_astarExe = new AstarExe(m_grid);
	m_astarExe->Start();

	int count = 0;

	while (window.isOpen())
	{
		count++;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (count % 10 == 0) {
			m_astarExe->Update();
		}

		window.clear();
		//window.draw(shape);
		m_grid->Draw(&window);
		window.display();
	}
	delete m_astarExe;
	delete m_grid;

    return 0;
}

