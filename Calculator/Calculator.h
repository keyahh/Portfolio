#ifndef CALCULATORH
#define CALCULATORH

//#include "..\Helper\Button.h";
#include "../Helper/Button.h"
#include "Display.h"
#include <vector>

class Calculator : public sf::RectangleShape
{
private:
	Display _display;
	std::vector<Button> buttons;
	std::vector<std::string> buttonKeys;

	float getSpacing(const Button& button);
	void createButtons();
	void setButtons(const sf::Vector2f& startPos = { 100, 250 });

public:
	explicit Calculator(const sf::Vector2f& size = {400.f, 866.6666f});
	//explicit prevents something like Calculator c = {x, y}

	Calculator(sf::RenderWindow& window);

	void clear();
	void update(float dt);
	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad);

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif