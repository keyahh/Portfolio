#include "Game.h"

Game::Game(const sf::Vector2f& windowSize)
{
    out.open("game_save.txt", std::ios::app);

    states.push(new MainMenuState(windowSize, &states));
    states.push(new TitleScreenState(windowSize, &states));
}

Game::Game(const Game& game)
{
    *this = game;
}

void Game::eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad)
{
    states.top()->eventHandler(window, event, dt);
}

void Game::update(float dt)
{
    if (!states.empty())
    {
        states.top()->update(dt);
        if (states.top()->getClose())
        {
            states.top()->close();
            delete states.top();
            states.pop();
        }
    }
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (!this->states.empty())
    {
        target.draw(*(this->states).top());
    }
}

Game& Game::operator=(const Game& game)
{
    this->states = game.states;
    return *this;
}

Game::~Game()
{
    while (!states.empty())
    {
        states.top()->close();
        delete states.top();
        states.pop();
    }
}