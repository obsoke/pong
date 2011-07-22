#include "sEnd.hpp"
#include "sGame.hpp"
#include "config.hpp"
#include "StateManager.hpp"

sEnd::sEnd(sf::RenderWindow& app, int win) :
    State(app)
{
    // load font for string
    if (!MyFont.LoadFromFile("PressStart2P.ttf"))
		return;
    
    // determine winner
    if(win)
    {
        winner.SetText("YUO LOSE");
    }
    else
    {
        winner.SetText("YOU WIN!");
    }
    
    // set text, size, position and fonts for strings
    congrats.SetText("CONGRATULATIONS!");
    playAgain.SetText("Play again? (y/n)");
    
    congrats.SetSize(40);
    winner.SetSize(35);
    playAgain.SetSize(30);
    
    congrats.SetPosition(screenWidth / 2 - 300, 100);
    winner.SetPosition(screenWidth / 2 - 125, 200);
    playAgain.SetPosition(screenWidth / 2 - 225, 500);
    
    congrats.SetFont(MyFont);
    winner.SetFont(MyFont);
    playAgain.SetFont(MyFont);
}
sEnd::~sEnd()
{
    
}
void sEnd::Draw()
{
    app.Clear();
    app.Draw(congrats);
    app.Draw(winner);
    app.Draw(playAgain);
    app.Display();
}
void sEnd::Update()
{
    // check whether to start new game or end based on player input
    if(app.GetInput().IsKeyDown(sf::Key::Y))
    {
        StateManager::Instance().addState(new sGame(app));
    }
    else if(app.GetInput().IsKeyDown(sf::Key::N))
    {
        StateManager::Instance().end();
    }
}