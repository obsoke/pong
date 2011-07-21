#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::RenderWindow app;
	sf::Event eHandler;
};

#endif