
#include <SFML\Graphics.hpp>

class Window{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();

	void BeginDraw() { m_window.clear(sf::Color::Black); }
	void EndDraw() { m_window.display(); }
	

	void Update();

	bool IsDone(){ return m_isDone; }
	bool IsFullScreen() { return m_isFullScreen; }
	sf::Vector2u GetWindowSize() { return m_windowSize; }

	void ToggleFullScreen();

	void Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }
private:
	void Setup(const std::string& l_title,const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullScreen;

};

Window::Window(){ Setup("Window", sf::Vector2u(640, 480)); }

Window::Window(const std::string& l_title, const sf::Vector2u& l_size){
	Setup(l_title, l_size);
}

Window::~Window(){ Destroy(); }

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size){
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isDone = false;
	m_isFullScreen = false;
	Create();
}

void Window::Create(){
	auto style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
}

void Window::Destroy(){ m_window.close(); }

void Window::Update(){
	sf::Event event;
	while (m_window.pollEvent(event)){
		if (event.type == sf::Event::Closed){ m_isDone = true; }
		if (event.key.code == sf::Keyboard::F5){ ToggleFullScreen(); }
	}
}

void Window::ToggleFullScreen(){
	m_isFullScreen = !m_isFullScreen;
	Destroy();
	Create();
}


