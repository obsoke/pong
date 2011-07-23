#include "ball.hpp"
#include "config.hpp"

Ball::Ball(float x, float y, float w, float h, float xS, float yS, bool vis) :
    Entity(x, y, w, h, vis),
    xSpeed(xS), ySpeed(yS)
{
    SetPosition(X, Y);
    SetScale(W, H);
    
    // load audio
    if(!wallHit.LoadFromFile("wallHit.wav"))
        return;
    
    if(!paddleHit.LoadFromFile("paddleHit.wav"))
        return;
}

void Ball::Update(sf::RenderWindow& app, Paddle& player1, Paddle& player2)
{
	// wall collision
	if(Y <= 0)
	{
		ySpeed *= -1;
		Y = 0;
        hit.SetBuffer(wallHit);
        hit.Play();
	}
	if(Y + H >= screenHeight)
	{
		ySpeed *= -1;
		Y = screenHeight - H;
        hit.SetBuffer(wallHit);
        hit.Play();
	}
	
	// paddle collision
	if(collides(player1))
	{
		xSpeed *= -1;
		while(collides(player1))
			++X;
        hit.SetBuffer(paddleHit);
        hit.Play();
	}
	if(collides(player2))
	{
		xSpeed *= -1;
		while(collides(player2))
			--X;
        hit.SetBuffer(paddleHit);
        hit.Play();
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