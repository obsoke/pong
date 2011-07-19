#include "config.hpp"
#include "game.hpp"
#include "toolbox.hpp"

Game::Game() :
	app(sf::VideoMode(screenWidth, screenHeight), name),
	ball(screenWidth / 2 - 8, screenHeight / 2 - 8, 16, 16, 250, 250, true),
	player1(16, 200, 16, 100, 225, true),
	player2(screenWidth - 16 * 2, 200, 16, 100, 225, true, ball)
{
	// set sprites colour
	ball.SetColor(sf::Color(255,0,0,255));
	player1.SetColor(sf::Color(0,255,0,255));
	player2.SetColor(sf::Color(0,255,0,255));

	// set strings
	score1.SetText(Toolbox::itos(player1.getScore()));
	score1.SetPosition(5, 0);
	score2.SetText(Toolbox::itos(player2.getScore()));
	score2.SetPosition(screenWidth - 20, 0);
	 
	// misc app stuff
	app.UseVerticalSync(true);
	app.SetFramerateLimit(60);
}

Game::~Game()
{
	// destructor stuff
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
		
		// scoring collision & event handling
		if(ball.X <= 0)
		{
			player2.Score();
			ball.ResetBall();
			score2.SetText(Toolbox::itos(player2.getScore()));
		}
		if(ball.X + ball.W >= screenWidth)
		{
			player1.Score();
			ball.ResetBall();
			score1.SetText(Toolbox::itos(player1.getScore()));
		}
		
		// check for win
		if(player1.getScore() == 5 || player2.getScore() == 5)
			running = false;
			
		update();
        draw();
    }	
}

void Game::update()
{
	player1.Update(app);
	player2.Update(app);
	ball.Update(app, player1, player2);
}

void Game::draw()
{
	app.Clear();
	player1.Draw(app);
	player2.Draw(app);
	ball.Draw(app);
	app.Draw(score1);
	app.Draw(score2);
	app.Display();
}