#ifndef SGAME_HPP
#define SGAME_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "ai.hpp"

class sGame : public State {
public:
	sGame(sf::RenderWindow& app);
	~sGame();
	void Draw();
	void Update();
private:
	sf::String score1;
	sf::String score2;
    sf::Font MyFont;
	Paddle player1;
	AI player2;
	Ball ball;	
};

#endif