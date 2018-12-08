#include "app.h"

App::App() {

}

int App::init(const int& winWidth, const int& winHeight, const std::string& title) {
	m_winWidth = winWidth;
	m_winHeight = winHeight;
	m_winTitle = title;
	m_isFullscreen = false; 
	m_win.create(sf::VideoMode(m_winWidth,m_winHeight),m_winTitle);



	return 1;
}

int App::run() {

	while (m_win.isOpen()) {
		
		this->pollEvents();

		m_win.clear();
		m_win.display();

	}
	

	return 1;
}

void App::pollEvents() {
		
	sf::Event e;
	while (m_win.pollEvent(e)) {
		
		if (e.type == sf::Event::Closed) {
			m_win.close();
		}
		else if (e.type == sf::Event::KeyPressed) {
			this->handleInput(e);
		}

	}

}

void App::handleInput(const sf::Event& e) {
		
	if (e.key.code == sf::Keyboard::Escape) {
		m_win.close();
	}

	if (e.key.code == sf::Keyboard::F) {
		if (!m_isFullscreen) {
			m_win.create(sf::VideoMode::getDesktopMode(),m_winTitle, sf::Style::Fullscreen);
			m_isFullscreen = true;
		}
		else {
			m_win.create(sf::VideoMode(m_winWidth, m_winHeight), m_winTitle);
			m_isFullscreen = false;
		}
	}

}
