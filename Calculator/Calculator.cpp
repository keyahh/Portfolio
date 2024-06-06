#include "Calculator.h"

Calculator::Calculator(sf::RenderWindow& window)
	: Calculator({ static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y) })
{
}

Calculator::Calculator(const sf::Vector2f& size)
{
	sf::RectangleShape::setSize(size);
	buttonKeys = { "C"," ^ "," % "," / ","7","8","9"," * ","4","5","6"," - ","1","2","3"," + ","Del", "0", ".","=" };
	createButtons();
	setButtons({size.x * 0.15f, this->getGlobalBounds().top + size.y * 0.2f});
	_display.setPosition({size.x * 0.15f, this->getGlobalBounds().top + size.y * 0.1f });
}

float Calculator::getSpacing(const Button& button)
{
	return button.getRadius() * 2.5;
}

void Calculator::createButtons()
{
	for (auto& bk : buttonKeys)
	{
		buttons.push_back(Button(bk, Fonts::getFont(Fonts::OPEN_SANS_REGULAR), 40));
	}

	for (int i = 0; i < buttons.size(); i++) //set colors
	{
		if ((i + 1) % 4 == 0 && i != 0)
		{
			buttons[i].setDefaultColor(ColorPalette::orange);
		}
		if (i < 3)
		{
			buttons[i].setDefaultColor(ColorPalette::darkGray);
		}
	}
}

void Calculator::setButtons(const sf::Vector2f& startPos)
{
	sf::Vector2f pos = startPos;
	float spacing = getSpacing(buttons.front());

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].setPosition(pos);

		pos.x += spacing;
		if ((i + 1) % 4 == 0 && i != 0)
		{
			pos.y += spacing;
			pos.x = startPos.x;
		}
	}
}

void Calculator::clear()
{
	_display.clear();
}

void Calculator::update(float dt)
{
	_display.update(dt);
	for (auto& b : buttons)
	{
		b.update(dt);
	}
}

void Calculator::eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad)
{
	for (auto& b : buttons)
	{
		b.eventHandler(window, event, dt, pad);

		if (b.getClicked())
		{
			if (std::string(b.getString()) == "C") //special cases
			{
				_display.clear();
			}
			else if (std::string(b.getString()) == "Del")
			{
				_display.pop_back();
			}
			else if (std::string(b.getString()) == "=")
			{
				_display.inputRPN();
			}

			else
			{
				_display.addInput(b.getString());
			}

			b.setClicked(false);
		}
	}
	_display.eventHandler(window, event);
}

void Calculator::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	for (auto& i : buttons)
	{
		window.draw(i);
	}
	window.draw(_display);
}