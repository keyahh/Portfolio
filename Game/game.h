#ifndef GAMEH
#define GAMEH

#include "GameState.h"
#include "TitleScreenState.h"
#include "MainMenuState.h"

class Game : public sf::Drawable
{
private:
	std::ofstream out;
	std::ifstream in;
	std::stack<State*> states;

public:
	Game(const sf::Vector2f& windowSize = {1980.f, 1020.f});
	Game(const Game& game);

	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad);
	void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Game& operator =(const Game& game);
	~Game();
};

#endif
