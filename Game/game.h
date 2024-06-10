#ifndef GAMEH
#define GAMEH

#include "GameState.h"
#include "TitleScreenState.h"
#include "MainMenuState.h"

class Game : public sf::Drawable
{
private:
	//sf::Event event;
	//sf::Clock clock;
	//sf::RenderWindow* window;
	std::ofstream out;
	std::ifstream in;
	//sf::RenderStates renderStates;
	//float dt = 0;
	std::stack<State*> states;

public:
	Game(const sf::Vector2f& windowSize = {1980.f, 1020.f});
	Game(const Game& game);
	//Game(sf::RenderWindow* window);

	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad);
	void update(float dt);
	//void render();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//void run();
	//void closeGame();

	Game& operator =(const Game& game);
	~Game();
};

#endif