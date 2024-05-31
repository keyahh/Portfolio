#ifndef MOUSEEVENTSH
#define MOUSEEVENTSH

#include "SFML/Graphics.hpp"

class MouseEvents
{
public:
	template <typename T>
	static bool isHovered(const T& obj, sf::RenderWindow& window);

	template <typename T>
	static bool isClicked(const T& obj, sf::RenderWindow& window);
};

#include "MouseEvents.cpp"

#endif