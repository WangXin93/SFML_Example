
#include "Window.h"

class Game{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
private:
	void MoveMushroom();
	Window m_window;
	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2f m_increment;
};

Game::Game() :m_window("Chaper 2", sf::Vector2u(800, 600)){
	//set up class members.
	m_mushroomTexture.loadFromFile("mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2f(0.4f, 0.4f);
}

Game::~Game() { }

void Game::HandleInput(){ }

Window* Game::GetWindow(){ return &m_window; }

void Game::Update(){
	m_window.Update();
	MoveMushroom();
}

void Game::Render(){
	m_window.BeginDraw();
	m_window.Draw(m_mushroom);
	m_window.EndDraw();
}

void Game::MoveMushroom(){
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();
	if ((m_mushroom.getPosition().x + l_textSize.x  > l_windSize.x && m_increment.x > 0)
		|| (m_mushroom.getPosition().x < 0 && m_increment.x < 0)){
		m_increment.x = -m_increment.x;
	}
	if ((m_mushroom.getPosition().y + l_textSize.y > l_windSize.y && m_increment.y > 0)
		|| (m_mushroom.getPosition().y < 0 && m_increment.y < 0)){
		m_increment.y = -m_increment.y;
	}
	m_mushroom.setPosition(m_mushroom.getPosition() + m_increment);
}

