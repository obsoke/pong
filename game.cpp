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
    bool running = true;
	
    // game loop
    while (app.IsOpened() && running)
    {
        // process special events
        while (app.GetEvent(eHandler))
        {
            // Close window : exit
            if (eHandler.Type == sf::Event::Closed)
                app.Close();
        }
        
        if(StateManager::Instance().getCurrentState())
        {
            StateManager::Instance().getCurrentState()->Update();
            if(StateManager::Instance().getCurrentState())
            {
                StateManager::Instance().getCurrentState()->Draw();   
            }
        }
        else running = false;
	}	
}