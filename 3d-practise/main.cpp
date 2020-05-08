#include "stdafx.h"
#include "Object3d.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 960), "3d");

	Object3d obj3d(sf::Vector2f(500, 500), sf::Vector3f(100, 100, 100));
	//obj3d.rotateAbsoluteX(0);
	//obj3d.rotateAbsoluteY(45);
	//obj3d.rotateAbsoluteZ(0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		//obj3d.rotateRelativeX(0.1);
		//obj3d.rotateRelativeY(0.1);
		obj3d.rotateRelativeZ(0.1);

		window.clear();
		obj3d.draw(window);
		window.display();
	}

	return 0;
}