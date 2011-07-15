#include "config.hpp"
#include "game.hpp"

Game::Game() :
	app(sf::VideoMode(screenWidth, screenHeight), name),
	ball(screenWidth / 2 - 8, screenHeight / 2 - 8, 16, 16, 250, 250, true),
	player1(16, 200, 16, 100, 225, true),
	player2(screenWidth - 16 * 2, 200, 16, 100, 225, true, ball)
{
	init();
}

Game::~Game()
{
	wrap();
}

void Game::init()
{
	if(!padImg.LoadFromFile("paddle.png"))
		return;
	if(!ballImg.LoadFromFile("ball.png"))
		return;
	player1.SetImage(padImg);
	player2.SetImage(padImg);
	ball.SetImage(ballImg);
	
	app.UseVerticalSync(true);
	app.SetFramerateLimit(60);
}

void Game::run()
{
	// Start game loop
    while (app.IsOpened())
    {
        // Process events
        while (app.GetEvent(eHandler))
        {
            // Close window : exit
            if (eHandler.Type == sf::Event::Closed)
                app.Close();
        }

		update();
        draw();
    }	
}

void Game::wrap()
{
	// do wrapping stuff here
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
	app.Display();
}