#include "Button.h"

Button::Button()
{
}

Button::Button(const std::string& text, const sf::Font& font)
	: Button(text, font, 50, ColorPalette::charcoal, ColorPalette::lightGray, sf::Color::White, 80)
{
}

Button::Button(const std::string& text, const sf::Font& font, const sf::Color& defaultColor)
	: Button(text, font, 50, defaultColor, ColorPalette::lightGray, sf::Color::White, 80)
{
}

Button::Button(const std::string& text, const sf::Font& font, const sf::Color& defaultColor, const sf::Color& hoverColor)
	: Button(text, font, 50, defaultColor, hoverColor, sf::Color::White, 80)
{
}


Button::Button(const std::string& text, const sf::Font& font, float buttonRadius)
	: Button(text, font, buttonRadius, ColorPalette::charcoal, ColorPalette::lightGray, sf::Color::White, 80)
{
}

Button::Button(const std::string& text, const sf::Font& font, float buttonRadius, int fontSize, const sf::Color& textColor, const sf::Color& defaultColor)
	: Button(text, font, buttonRadius, defaultColor, ColorPalette::lightGray, textColor, 80)
{
}

Button::Button(const std::string& text, const sf::Font& font, float buttonRadius, const sf::Color& defaultColor, const sf::Color& hoverColor, const sf::Color& textColor, int fontSize)
	: defaultColor(defaultColor), hoverColor(hoverColor), sf::CircleShape(buttonRadius)
{
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);

	sf::CircleShape::setFillColor(defaultColor);
}

void Button::eventHandler(sf::RenderWindow& window, sf::Event event, float dt)
{
	if (MouseEvents::isHovered(*this, window))
	{
		sf::CircleShape::setFillColor(hoverColor);
	}
	else
	{
		sf::CircleShape::setFillColor(defaultColor);
	}

	if (MouseEvents::isClicked(*this, window) && canClick)
	{
		clicked = true;
	}
}

const std::string& Button::getValue() const
{
	return text.getString();
}

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::CircleShape circle = *this;
	window.draw(circle);
	window.draw(text);
}

void Button::setPosition(const sf::Vector2f& position)
{
	sf::CircleShape::setPosition(position);
	centerText();
}

void Button::update(float dt)
{
	clickTime += dt;
	if (clickTime >= clickCoolDown)
	{
		clickTime = 0;
		canClick = true;
		clicked = false;
	}
}

void Button::setDefaultColor(const sf::Color& defaultColor)
{
	Button::defaultColor = defaultColor;
	sf::CircleShape::setFillColor(defaultColor);
}

void Button::setHoverColor(const sf::Color& hoverColor)
{
	Button::hoverColor = hoverColor;
}

void Button::centerText()
{
	sf::FloatRect textRect = text.getGlobalBounds();
	sf::FloatRect tRect = getGlobalBounds();

	sf::Vector2f center = { textRect.width / 2.0f, textRect.height / 2.f };
	sf::Vector2f localBounds = { center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top };
	sf::Vector2f rounded = { std::round(localBounds.x), std::round(localBounds.y) };
	text.setOrigin(rounded);
	text.setPosition({ tRect.left + tRect.width / 2, tRect.top + tRect.height / 2 });
}