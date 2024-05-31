#ifndef BUTTON
#define BUTTON

#include "MouseEvents.h"
#include "ColorPalette.h"
#include "Fonts.h"
#include "Position.h"
#include <string>
#include <iostream>

class Button : public sf::CircleShape
{
private:
	sf::Text text;
	sf::Color defaultColor, hoverColor;
	bool canClick = true, clicked = false;
	float clickCoolDown = 0.1, clickTime = 0;

	void centerText();

public:
	Button();
	Button(const std::string& text, const sf::Font& font);
	Button(const std::string& text, const sf::Font& font, const sf::Color& defaultColor);
	Button(const std::string& text, const sf::Font& font, const sf::Color& defaultColor, const sf::Color& hoverColor);
	Button(const std::string& text, const sf::Font& font, float buttonRadius);
	Button(const std::string& text, const sf::Font& font, float buttonRadius, int fontSize, const sf::Color& textColor, const sf::Color& defaultColor);
	Button(const std::string& text, const sf::Font& font, float buttonRadius, const sf::Color& defaultColor = ColorPalette::darkGray, const sf::Color& hoverColor = ColorPalette::lightGray, const sf::Color& textColor = sf::Color::White, int fontSize = 100);


	void eventHandler(sf::RenderWindow& window, sf::Event event, float dt);
	const std::string& getValue() const;

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void setPosition(const sf::Vector2f& position);

	void update(float dt);

	void setDefaultColor(const sf::Color& defaultColor);
	void setHoverColor(const sf::Color& hoverColor);
};

#endif