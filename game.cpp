#include "config.hpp"
#include "game.hpp"
#include "toolbox.hpp"
#include "sGame.hpp"
#include "sTitle.hpp"
#include "StateManager.hpp"

Game::Game() :
	app(sf::VideoMode(screenWidth, screenHeight), name)
{	
	// add states to managers
	StateManager::Instance().addState(new sTitle(app));
	
	// misc app stuff
	app.UseVerticalSync(true);
	app.SetFramerateLimit(60);
}

Game::~Game()
{
	StateManager::Instance().clearAll();
}

void Game::run()
{	
	// game loop
    while (app.IsOpened())
    {
        // process special events
        while (app.GetEvent(eHandler))
        {
            // Close window : exit
            if (eHandler.Type == sf::Event::Closed)
                app.Close();
        }
		StateManager::Instance().getCurrentState()->Update();
		StateManager::Instance().getCurrentState()->Draw();
	}	
}