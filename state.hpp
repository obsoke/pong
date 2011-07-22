#ifndef STATE_HPP
#define STATE_HPP

namespace sf 
{
	class RenderWindow;
}

class State
{
protected:
	sf::RenderWindow& app;
public:
	State(sf::RenderWindow& a) : app(a) { }
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

#endif