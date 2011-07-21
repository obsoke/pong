#ifndef BALL_HPP
#define BALL_HPP

#include "entity.hpp"
#include "paddle.hpp"

class Ball : public Entity {
private:
	float xSpeed;
	float ySpeed;
public:
	Ball(float x, float y, float w, float h, float xS, float yS, bool vis) :
		Entity(x, y, w, h, vis),
		xSpeed(xS), ySpeed(yS)
	{
		SetPosition(X, Y);
		SetScale(W, H);
	}
	void ResetBall();
	void Update(sf::RenderWindow& app) { } // to appease compiler
	void Update(sf::RenderWindow& app, Paddle& player1, Paddle& player2);
	void Draw(sf::RenderWindow& app);
};

#endif