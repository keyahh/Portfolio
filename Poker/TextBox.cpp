#include "TextBox.h"

TextBox::TextBox()
{
	setSize({ 300, 50 });
	setFillColor(sf::Color::White);
}

TextBox::TextBox(const std::string& text, const sf::Font& font, const sf::Vector2f& size)
	:name(text)
{
	setSize(size);
	setFillColor(sf::Color::White);
	TextBox::text = sf::Text(text, font, 24);
	TextBox::text.setFillColor(sf::Color::Black);
	updateScore(0);
	alignLeft(*this, TextBox::text);
}

void TextBox::alignLeft(const sf::Shape& obj, sf::Text& text)
{
	text.setPosition((obj.getGlobalBounds().left + 10), (obj.getGlobalBounds().top + obj.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 1.5));
}

void TextBox::centerText(const sf::Shape& obj, sf::Text& text)
{
	text.setPosition((obj.getGlobalBounds().left + obj.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2),
		(obj.getGlobalBounds().top + obj.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 1.5));
}

void TextBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::RectangleShape parent = *this;
	window.draw(parent);
	window.draw(text);
}

void TextBox::setPosition(const sf::Vector2f& position, int alignment)
{
	sf::RectangleShape::setPosition(position);

	switch (alignment)
	{
	case 0:
		alignLeft(*this, text);
	case 1:
		centerText(*this, text);
	}
}

void TextBox::setPosition(const sf::Vector2f& position)
{
	sf::RectangleShape::setPosition(position);
	alignLeft(*this, text);
}

void TextBox::setText(const std::string& text)
{
	TextBox::text.setString(text);
}

void TextBox::setTextObj(const std::string& text, const sf::Font& font, int fontSize)
{
	TextBox::text.setFillColor(sf::Color::Black);
	TextBox::text = sf::Text(text, font, fontSize);
}

void TextBox::updateScore(int score)
{
	TextBox::text.setString(name + std::to_string(score));
}

void TextBox::centerText()
{
	centerText(*this, text);
}

const std::string& TextBox::getName() const
{
	return name;
}