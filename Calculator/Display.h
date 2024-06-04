#ifndef DISPLAYH
#define DISPLAYH

#include "SFML/Graphics.hpp"
#include "../Helper/Fonts.h"
#include "RPN.h"
#include "../Helper/Position.h"
#include <string>

class Display : public sf::RectangleShape
{
private:
	sf::Text text;
	double inputCoolDown = 0.2, inputCoolDownTime = 0;
	bool gotInput = false;

	void getKeyboardInput();
	bool checkKeyPress();

public:
	Display();

	void pop_back();
	void eventHandler(sf::RenderWindow& window, sf::Event event);
	void update(float dt);
	void clear();
	void addInput(const std::string& string);
	void addInput(const sf::String& string);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void setPosition(const sf::Vector2f& pos);
	void inputRPN();

	std::string getValue();
};

#endif