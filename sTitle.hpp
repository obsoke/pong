#ifndef STITLE_HPP
#define STITLE_HPP
#include <SFML/Graphics.hpp>
#include "State.hpp"

class sTitle : public State {
public:
	sTitle(sf::RenderWindow& app);
	~sTitle();
	void Draw();
	void Update();
private:
	sf::Font MyFont;
	sf::String title;
	sf::String author;
	sf::String pressReturn;
	
};

#endif