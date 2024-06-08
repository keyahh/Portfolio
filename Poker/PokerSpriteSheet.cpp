#include "PokerSpriteSheet.h"

PokerSpriteSheet::PokerSpriteSheet()
	: PokerSpriteSheet("Deck.png", 4, 13)
{
}

PokerSpriteSheet::PokerSpriteSheet(const std::string& imgPath, int rows, int cols)
{
	init(imgPath, rows, cols);
}

void PokerSpriteSheet::init(const std::string& imgPath, int rows, int cols)
{
	if (!texture.loadFromFile(imgPath))
		exit(28);
	int width = texture.getSize().x;
	int height = texture.getSize().y;

	intRect.width = width / cols;
	intRect.height = height / rows;
	//pos defaults at 0,0

	sprite.setTextureRect(intRect);
	sprite.setTexture(texture);
	//sprite.setScale(2.5, 2.5);
}

void PokerSpriteSheet::animate()
{
	if (clock.getElapsedTime().asMilliseconds() > 250)
	{
		intRect.left += intRect.width;
		if (intRect.left + intRect.width >= texture.getSize().x) 
		{
			intRect.left = 0;
			intRect.top += intRect.height;
			if (intRect.top == texture.getSize().y) 
			{
				intRect.top = 0;
			}
		}
		sprite.setTextureRect(intRect);
		clock.restart();
	}
}

void PokerSpriteSheet::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	window.draw(PokerSpriteSheet::sprite);
}

void PokerSpriteSheet::setIntRectPos(int x, int y)
{
	intRect.left = x;
	intRect.top = y;
	sprite.setTextureRect(intRect);
}

void PokerSpriteSheet::setRowCol(int row, int col)
{
	intRect.left = col * intRect.width;
	intRect.top = row * intRect.height;
	sprite.setTextureRect(intRect);
}

sf::Sprite& PokerSpriteSheet::getSprite()
{
	return sprite;
}
