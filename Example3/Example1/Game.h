#pragma once
#include "Window.h"
#include "World.h"
#include "Textbox.h"

class Game{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	void RestartClock();
private:
	void MoveMushroom();
	Window m_window;
	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2f m_increment;
	float m_elapsed;
	sf::Clock m_clock;
	float m_frametime = 1.0f / 60.0f;

	World m_world;
	Snake m_snake;
	Textbox m_textbox;
};

Game::Game() :m_window("Snake", sf::Vector2u(800, 600)),m_snake(m_world.GetBlockSize()),
m_world(sf::Vector2u(800, 600)), m_textbox(5, 14, 350, sf::Vector2f(225,0))
{
	//set up class members.
	m_mushroomTexture.loadFromFile("mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2f(400.0f, 400.0f);
	m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
}

Game::~Game() { }

void Game::HandleInput(){ 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_snake.GetPhysicalDirection() != Direction::Down)
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_snake.GetPhysicalDirection() != Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_snake.GetPhysicalDirection() != Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& m_snake.GetPhysicalDirection() != Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

Window* Game::GetWindow(){ return &m_window; }

void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }

void Game::Update(){
	m_window.Update();

	float timestep = 1.0f / m_snake.GetSpeed();
	if (m_elapsed >= timestep){
		m_snake.Tick();
		m_world.Update(m_snake,m_textbox);
		m_elapsed -= timestep;
		if (m_snake.HasLost()){
			m_snake.Reset();
		}
	}
}

void Game::Render(){
	m_window.BeginDraw();
	m_world.Render(m_window.GetRenderWindow());
	m_snake.Render(m_window.GetRenderWindow());
	m_textbox.Render(m_window.GetRenderWindow());
	m_window.EndDraw();
}


