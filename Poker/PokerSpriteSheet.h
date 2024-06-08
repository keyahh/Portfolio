#ifndef POKERSPRITESHEET
#define POKERSPRITESHEET
#include "SFML/Graphics.hpp"
#include <string>

class PokerSpriteSheet : public sf::Drawable, public sf::Transformable
{
private:
	sf::Sprite sprite; //need top, left, width, and height of card
	sf::IntRect intRect; //gets moved around sprite sheet to display the section bounded
	sf::Texture texture;
	sf::Clock clock;

	void init(const std::string& imgPath, int rows, int cols);
public:
	PokerSpriteSheet();
	PokerSpriteSheet(const std::string& imgPath, int rows, int cols);

	void animate();
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

	void setIntRectPos(int x, int y);
	void setRowCol(int row, int col);
	sf::Sprite& getSprite();
};
#endif