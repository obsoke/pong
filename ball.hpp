#ifndef BALL_HPP
#define BALL_HPP

#include "entity.hpp"
#include "paddle.hpp"
#include <SFML/Audio.hpp>

class Ball : public Entity {
private:
	float xSpeed;
	float ySpeed;
    sf::Sound hit;
    sf::SoundBuffer wallHit;
    sf::SoundBuffer paddleHit;
    
public:
	Ball(float x, float y, float w, float h, float xS, float yS, bool vis);
	void ResetBall();
	void Update(sf::RenderWindow& app) { } // to appease compiler
	void Update(sf::RenderWindow& app, Paddle& player1, Paddle& player2);
	void Draw(sf::RenderWindow& app);
};

#endif