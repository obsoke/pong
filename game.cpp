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
        
        // only perform update/draw if a state exists
        if(StateManager::Instance().getCurrentState())
        {
            StateManager::Instance().getCurrentState()->Update();
            
            // only perform draw if a state exists after last update
            if(StateManager::Instance().getCurrentState())
            {
                StateManager::Instance().getCurrentState()->Draw();   
            }
        }
        
        // if no state, end game
        else running = false;
	}	
}