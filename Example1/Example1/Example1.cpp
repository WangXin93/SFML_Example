// Example1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Mushroom Window");
	sf::Texture mushroomTexture;
	if (!mushroomTexture.loadFromFile("mushroom.png")){
		cout << "Error! Fail to load texture." << endl;
		return -1;
	}
	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2u size = mushroomTexture.getSize();
	mushroom.setOrigin(size.x / 2, size.y / 2);
	mushroom.setColor(sf::Color(255, 0, 0, 255));
	sf::Vector2f increment(0.1f, 0.1f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if ((mushroom.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0)
			|| (mushroom.getPosition().x - (size.x / 2) < 0 && increment.x < 0)){
			increment.x = -increment.x;
		}
		if ((mushroom.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0)
			|| (mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0)){
			increment.y = -increment.y;
		}

		mushroom.setPosition(mushroom.getPosition() + increment);
		window.clear(sf::Color(16,16,16,255));
		window.draw(mushroom);
		window.display();
	}
	return 0;
}

