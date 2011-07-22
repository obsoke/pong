#include "ball.hpp"
#include "config.hpp"

void Ball::Update(sf::RenderWindow& app, Paddle& player1, Paddle& player2)
{
	// wall collision
	if(Y <= 0)
	{
		ySpeed *= -1;
		Y = 0;
	}
	if(Y + H >= screenHeight)
	{
		ySpeed *= -1;
		Y = screenHeight - H;
	}
	
	// paddle collision
	if(collides(player1))
	{
		xSpeed *= -1;
		while(collides(player1))
			++X;
	}
	if(collides(player2))
	{
		xSpeed *= -1;
		while(collides(player2))
			--X;
	}
	
	// adjust position
	X += xSpeed * app.GetFrameTime();
	Y += ySpeed * app.GetFrameTime();
	SetPosition(X, Y);
}

void Ball::ResetBall()
{
    // TO DO: make this better... right now its lame
	X = screenWidth / 2;
	Y = screenHeight / 2;
}

void Ball::Draw(sf::RenderWindow& app)
{
	if(isVisible())
		app.Draw(*this);
}