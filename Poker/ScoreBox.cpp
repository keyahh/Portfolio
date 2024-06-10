#include "ScoreBox.h"

ScoreBox::ScoreBox()
{
	setSize({ 300, 50 });
	setFillColor(sf::Color::White);
}

ScoreBox::ScoreBox(const std::string& text, const sf::Font& font, const sf::Vector2f& size)
	:name(text)
{
	setSize(size);
	setFillColor(sf::Color::White);
	ScoreBox::text = sf::Text(text, font, 24);
	ScoreBox::text.setFillColor(sf::Color::Black);
	updateScore(0);
	alignLeft(*this, ScoreBox::text);
}

void ScoreBox::alignLeft(const sf::Shape& obj, sf::Text& text)
{
	text.setPosition((obj.getGlobalBounds().left + 10), (obj.getGlobalBounds().top + obj.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 1.5));
}

void ScoreBox::centerText(const sf::Shape& obj, sf::Text& text)
{
	text.setPosition((obj.getGlobalBounds().left + obj.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2),
		(obj.getGlobalBounds().top + obj.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 1.5));
}

void ScoreBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::RectangleShape parent = *this;
	window.draw(parent);
	window.draw(text);
}

void ScoreBox::setPosition(const sf::Vector2f& position, int alignment)
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

void ScoreBox::setPosition(const sf::Vector2f& position)
{
	sf::RectangleShape::setPosition(position);
	alignLeft(*this, text);
}

void ScoreBox::setText(const std::string& text)
{
	ScoreBox::text.setString(text);
}

void ScoreBox::setTextObj(const std::string& text, const sf::Font& font, int fontSize)
{
	ScoreBox::text.setFillColor(sf::Color::Black);
	ScoreBox::text = sf::Text(text, font, fontSize);
}

void ScoreBox::updateScore(int score)
{
	ScoreBox::text.setString(name + std::to_string(score));
}

void ScoreBox::centerText()
{
	centerText(*this, text);
}

const std::string& ScoreBox::getName() const
{
	return name;
}