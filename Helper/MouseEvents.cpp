#ifndef MOUSEEVENTSCPP
#define MOUSEEVENTSCPP

#include "MouseEvents.h"


template <typename T>
bool MouseEvents::isHovered(const T& obj, sf::RenderWindow& window)
{
	return obj.sf::Shape::getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window));
}

template<typename T>
bool MouseEvents::isClicked(const T& obj, sf::RenderWindow& window)
{
	return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif