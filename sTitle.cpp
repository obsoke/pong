#include "sTitle.hpp"
#include "sGame.hpp"
#include "config.hpp"
#include "StateManager.hpp"

sTitle::sTitle(sf::RenderWindow& app) :
	State(app)
{
	if (!MyFont.LoadFromFile("PressStart2P.ttf"))
        return;
	
    // title set up
	title.SetText("PONG");
	title.SetFont(MyFont);
	title.SetSize(50);
	title.SetPosition(screenWidth / 2 - 100, 100);
	title.SetColor(sf::Color(0,255,0,255));
	
	// press return
	pressReturn.SetText("Press Enter to play");
	pressReturn.SetFont(MyFont);
	pressReturn.SetPosition(screenWidth / 2 - 260, 400);
	
}

sTitle::~sTitle()
{
	// destruct stuff
}

void sTitle::Draw()
{
	app.Clear();
	app.Draw(title);
	app.Draw(pressReturn);
	app.Display();
}

void sTitle::Update()
{
    // check for player input to start game
	if(app.GetInput().IsKeyDown(sf::Key::Return))
		StateManager::Instance().addState(new sGame(app));

}