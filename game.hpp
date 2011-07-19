#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "ball.hpp"
#include "ai.hpp"

class Game
{
public:
	Game();
	~Game();
	void run();
	void update();
	void draw();
private:
	sf::RenderWindow app;
	sf::Event eHandler;
	sf::Image padImg;
	sf::Image ballImg;
	sf::String score1;
	sf::String score2;
	Paddle player1;
	AI player2;
	Ball ball;
};
#endif