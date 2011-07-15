#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite {
public:
	// properties
	float X;
	float Y;
	float W;
	float H;
	
	// constructor
	Entity(float x, float y, float w, float h, bool vis)
	{
		X = x;
		Y = y;
		W = w;
		H = h;
		visible = vis;
	}
	
	// methods
	virtual void Update(sf::RenderWindow& app) = 0;
	virtual void Draw(sf::RenderWindow& app) = 0;
	bool collides(Entity& other)
	{
		if (&other==this) return false; // just in case.
		return getSmallRect().Intersects(other.getSmallRect());
	}
	sf::FloatRect getSmallRect()
	{
		return sf::FloatRect(X, Y, X + W, Y + H);
	}
	bool isVisible()
	{
		return visible;
	}
	void toggleVisible()
	{
		visible = !visible;
	}
private:
	Entity(); // no use of default constructor allowed
	bool visible;
};
#endif

