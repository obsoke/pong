#ifndef SEND_HPP
#define SEND_HPP

#include "sEnd.hpp"
#include "state.hpp"
#include <SFML/Graphics.hpp>

class sEnd : public State {
private:
    sf::Font MyFont;
    sf::String winner;
    sf::String congrats;
    sf::String playAgain;
    
public:
    sEnd(sf::RenderWindow& app, int win);
    ~sEnd();
    void Draw();
	void Update();
};

#endif
