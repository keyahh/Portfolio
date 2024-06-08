#ifndef TEXTBOX
#define TEXTBOX

#include <SFML/Graphics.hpp>
#include <string>

class TextBox : public sf::RectangleShape
{
private:
	sf::Text text;
	std::string name;
	void centerText(const sf::Shape& obj, sf::Text& text);
	void alignLeft(const sf::Shape& obj, sf::Text& text);
	
public:
	TextBox();
	TextBox(const std::string& text, const sf::Font& font, const sf::Vector2f& size);

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void setPosition(const sf::Vector2f& position, int alignment);
	virtual void setPosition(const sf::Vector2f& position);

	void setText(const std::string& text);
	void setTextObj(const std::string& text, const sf::Font& font, int fontSize);
	void updateScore(int score);

	void centerText();
	const std::string& getName() const;
};

#endif
