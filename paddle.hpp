#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "entity.hpp"

class Paddle : public Entity {
protected:
	float defaultSpeed;
	int score;
public:
	Paddle(float x, float y, float w, float h, float ds, bool vis);
	void Update(sf::RenderWindow& app);
	void Draw(sf::RenderWindow& app);
	void Score() { ++score; }
	int getScore() { return score; }
};

#endif