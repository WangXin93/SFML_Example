// Example1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Game game;
	while (!game.GetWindow()->IsDone()){
		//Game loop
		game.HandleInput();
		game.Update();
		game.Render();
		//sf::sleep(sf::seconds(0.01));
		game.RestartClock();
	}
	return 0;
}

