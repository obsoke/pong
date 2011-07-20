#include "sTitle.hpp"
#include "sGame.hpp"
#include "config.hpp"
#include "StateManager.hpp"

sTitle::sTitle(sf::RenderWindow& app) :
	State(app)
{
	if (!MyFont.LoadFromFile("PressStart2P.ttf"))
		return;
	
	title.SetText("PONG");
	title.SetFont(MyFont);
	title.SetSize(50);
	title.SetPosition(screenWidth / 2 - 100, 100);
	title.SetColor(sf::Color(0,255,0,255));
	
	// author
	author.SetText("Coded by Dale Karp");
	author.SetFont(MyFont);
	author.SetPosition(screenWidth / 2 - 250, 200);
	
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
	app.Draw(author);
	app.Draw(pressReturn);
	app.Display();
}

void sTitle::Update()
{
	if(app.GetInput().IsKeyDown(sf::Key::Return))
		StateManager::Instance().addState(new sGame(app));

}