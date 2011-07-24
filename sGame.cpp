#include "sGame.hpp"
#include "sEnd.hpp"
#include "StateManager.hpp"
#include "toolbox.hpp"
#include "config.hpp"

sGame::sGame(sf::RenderWindow& app) :
	State(app),
	ball(screenWidth / 2 - 8, screenHeight / 2 - 8, 16, 16, 250, 250, true),
	player1(16, 200, 16, 100, 225, true),
	player2(screenWidth - 16 * 2, 200, 16, 100, 225, true, ball)
{
	// set sprites colours	
	ball.SetColor(sf::Color(255,0,0,255));

	// set strings
    if(!MyFont.LoadFromFile("PressStart2P.ttf"))
        return;
       
	score1.SetText(Toolbox::itos(player1.getScore()));
	score1.SetPosition(5, 0);
    score1.SetFont(MyFont);
	score2.SetText(Toolbox::itos(player2.getScore()));
	score2.SetPosition(screenWidth - 30, 0);
    score2.SetFont(MyFont);
}

sGame::~sGame()
{
	// destruct stuff
}

void sGame::Draw()
{
	app.Clear();
	player1.Draw(app);
	player2.Draw(app);
	ball.Draw(app);
	app.Draw(score1);
	app.Draw(score2);
	app.Display();
}

void sGame::Update()
{
	// scoring collision & event handling
	if(ball.X <= 0)
	{
		player2.Score();
		ball.ResetBall(1);
		score2.SetText(Toolbox::itos(player2.getScore()));
	}
	if(ball.X + ball.W >= screenWidth)
	{
		player1.Score();
		ball.ResetBall(0);
		score1.SetText(Toolbox::itos(player1.getScore()));
	}
    
    // check for winner
    if(player1.getScore() == winNumber)
    {
        StateManager::Instance().addState(new sEnd(app, 0));
    }
    else if(player2.getScore() == winNumber)
    {
        StateManager::Instance().addState(new sEnd(app, 1));
    }
	
	player1.Update(app);
	player2.Update(app);
	ball.Update(app, player1, player2);
}