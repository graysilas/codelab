#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
 
class App {

public:
	
	App();

	int init(const int& winWidth, const int& winHeight, const std::string& title);

	int run();


private:

	void pollEvents();
	void handleInput(const sf::Event& e);


private:

	sf::RenderWindow m_win;
	unsigned int m_winWidth;
	unsigned int m_winHeight;
	std::string m_winTitle;
	bool m_isFullscreen;

};
