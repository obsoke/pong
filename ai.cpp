#include "ai.hpp"
#include "config.hpp"

void AI::Update(sf::RenderWindow& app)
{
	float speed = 0;
	
	if(ball.Y < Y)
	{
		if(Y > 0)
			speed = -defaultSpeed;
	}
	if(ball.Y > Y)
	{
		if(Y + H < screenHeight)
			speed = defaultSpeed;
	}
	
	Y += speed * app.GetFrameTime();
	
	SetPosition(X, Y);
}