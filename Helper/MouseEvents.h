#ifndef MOUSEEVENTSH
#define MOUSEEVENTSH

#include "SFML/Graphics.hpp"

class MouseEvents
{
public:
	template <typename T>
	static bool isHovered(const T& obj, sf::RenderWindow& window, int padding = 100);

	template <typename T>
	static bool isClicked(const T& obj, sf::RenderWindow& window, int padding = 100);
};

#include "MouseEvents.cpp"

#endif