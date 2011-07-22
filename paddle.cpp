#include "paddle.hpp"
#include "config.hpp"

Paddle::Paddle(float x, float y, float w, float h, float ds, bool vis) :
	Entity(x, y, w, h, vis), defaultSpeed(ds), score(0)
{
	SetPosition(X, Y);
	SetScale(W, H);
}
void Paddle::Update(sf::RenderWindow& app)
{	
	float speed = 0;
	
    // get player input
	if(app.GetInput().IsKeyDown(sf::Key::Up))
	{
		if(Y > 0)
			speed = -defaultSpeed;
	}
	if(app.GetInput().IsKeyDown(sf::Key::Down))
	{
		if(Y + H < screenHeight)
			speed = defaultSpeed;
	}
	
	Y += speed * app.GetFrameTime();
	
	SetPosition(X, Y);
}
void Paddle::Draw(sf::RenderWindow& app)
{
	if(isVisible())
		app.Draw(*this);
}