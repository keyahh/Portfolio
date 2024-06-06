#include "Display.h"

Display::Display()
{
	sf::RectangleShape::setFillColor(sf::Color::Black);
	//font.loadFromFile("opensans.ttf");
	text.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	text.setString("");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(48);
	Position::right(*this, text);
}

void Display::eventHandler(sf::RenderWindow& window, sf::Event event)
{
	if (!gotInput && checkKeyPress())
	{
		getKeyboardInput();
	}
}

void Display::getKeyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		text.setString(text.getString() + " + ");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen))
	{
		text.setString(text.getString() + " - ");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		text.setString(text.getString() + " * ");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
	{
		text.setString(text.getString() + " / ");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		text.setString(text.getString() + " ^ ");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		text.setString(text.getString() + " % ");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		inputRPN();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && text.getString().getSize() > 0)
	{
		/*std::string textStr = text.getString();
		textStr.pop_back();
		text.setString(textStr);*/
		pop_back();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		text.setString(text.getString() + " ");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		text.setString(text.getString() + "1");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		text.setString(text.getString() + "2");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		text.setString(text.getString() + "3");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		text.setString(text.getString() + "4");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		text.setString(text.getString() + "5");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		text.setString(text.getString() + "6");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		text.setString(text.getString() + "7");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		text.setString(text.getString() + "8");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		text.setString(text.getString() + "9");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		text.setString(text.getString() + "0");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		clear();
	}
}

void Display::pop_back()
{
	if(!text.getString().isEmpty())
	{
		std::string textStr = text.getString();
		textStr.pop_back();
		text.setString(textStr);
	}
}

void Display::update(float dt)
{
	if (gotInput)
	{
		inputCoolDownTime += dt;
		if (inputCoolDownTime >= inputCoolDown)
		{
			inputCoolDownTime = 0;
			gotInput = false;
		}
	}
}

void Display::inputRPN()
{
	if(!text.getString().isEmpty())
	{
		Postfix pf(text.getString());
		Term ans = RPN::evaluate(pf);
		if (ans.getOp() == ' ')
		{
			clear();
		}
		else
			text.setString(std::to_string(ans.getNumber()));
	}
}

void Display::clear()
{
	text.setString("");
}

void Display::addInput(const std::string& string)
{
	text.setString(text.getString() + string);
}

void Display::addInput(const sf::String& string)
{
	text.setString(text.getString() + string);
}

void Display::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::RectangleShape rect = *this;
	window.draw(rect);
	window.draw(text);
}

void Display::setPosition(const sf::Vector2f& pos)
{
	sf::RectangleShape::setPosition(pos);
	Position::right(*this, text);
}

std::string Display::getValue()
{
	return text.getString();
}

bool Display::checkKeyPress()
{
	for (int i = -1; i < sf::Keyboard::KeyCount; i++)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
		{
			gotInput = true;
			return true;
		}
	}
	return false;
}