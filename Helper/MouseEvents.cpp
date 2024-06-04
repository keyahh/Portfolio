#ifndef MOUSEEVENTSCPP
#define MOUSEEVENTSCPP

#include "MouseEvents.h"


template <typename T>
bool MouseEvents::isHovered(const T& obj, sf::RenderWindow& window, int padding)
{
	sf::FloatRect fr = { obj.sf::Shape::getGlobalBounds().left + padding, obj.sf::Shape::getGlobalBounds().top + padding, obj.sf::Shape::getGlobalBounds().width - padding * 2, obj.sf::Shape::getGlobalBounds().height - padding * 2 };
	//return obj.sf::Shape::getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window));
	return fr.contains((sf::Vector2f)sf::Mouse::getPosition(window));
}

template<typename T>
bool MouseEvents::isClicked(const T& obj, sf::RenderWindow& window, int padding)
{
	return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif