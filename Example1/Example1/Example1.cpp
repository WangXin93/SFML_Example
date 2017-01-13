// Example1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "First Window!");
	sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(320, 240);
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		window.draw(rectangle);
		window.display();
	}
	return 0;
}

