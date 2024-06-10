#ifndef POKERSPRITESHEET
#define POKERSPRITESHEET
#include "SFML/Graphics.hpp"
#include "../Helper/Textures.h"
#include <string>

class PokerSpriteSheet : public sf::Sprite
{
private:
	sf::IntRect intRect; //gets moved around sprite sheet to display the section bounded
	sf::Texture texture;
	sf::Clock clock;

	void init(const std::string& imgPath, int rows, int cols);
public:
	PokerSpriteSheet();
	PokerSpriteSheet(const std::string& imgPath, int rows, int cols);

	void animate();

	void setIntRectPos(int x, int y);
	void setRowCol(int row, int col);
};
#endif