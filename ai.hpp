#ifndef AI_HPP
#define AI_HPP
#include "paddle.hpp"
#include "ball.hpp"

class AI : public Paddle {
public:
	AI(float x, float y, float w, float h, float ds, bool vis, Ball& b) :
		Paddle(x, y, w, h, ds, vis),
		ball(b)
	{
	}
	void Update(sf::RenderWindow& app);
private:
	Ball& ball;
};
#endif