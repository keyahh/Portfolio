#include "Portfolio.h"


Portfolio::Portfolio(sf::VideoMode videoMode, std::string windowName)
{
	window.create(videoMode, windowName);
	window.setFramerateLimit(60);
}

void Portfolio::run()
{
	init();

	while (window.isOpen())
	{
		eventHandler(window, event);

		dt = clock.restart().asSeconds();

		left.update(dt);
		right.update(dt);
		(*iter)->update(dt);
		
		render();

	}
}

void Portfolio::addProgram(Program& program)
{
	programs.push_back(&program);

}

void Portfolio::eventHandler(sf::RenderWindow& window, sf::Event event)
{
	if (window.pollEvent(event))
	{
		(*iter)->eventHandler(window, event, dt);

		left.eventHandler(window, event, dt);
		right.eventHandler(window, event, dt);

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (left.getClicked())
		{
			moveLeft();
			left.setClicked(false);
		}
		if (right.getClicked())
		{
			moveRight();
			right.setClicked(false);
		}
	}
}

void Portfolio::render()
{
	window.clear();
	texture.clear();

	texture.draw(*(*iter));
	display.setTexture(texture.getTexture());
	window.draw(display);

	window.draw(left);
	window.draw(right);
	window.draw(title);

	texture.display();
	window.display();
}

void Portfolio::init()
{
	setupIter();
	//setupDisplay();
	setupButtons();
	setupTitle();
}

void Portfolio::setupDisplay()
{
	texture.create(window.getSize().x - padding * 2, window.getSize().y - padding * 3.5);
	display.setTexture(texture.getTexture());
	display.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
	display.setPosition(padding, padding);
}

void Portfolio::setupButtons()
{
	left.create("<", Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	right.create(">", Fonts::getFont(Fonts::OPEN_SANS_REGULAR));

	left.setPosition({padding, static_cast<float>(window.getSize().y) * 0.8f});
	right.setPosition({ static_cast<float>(window.getSize().x) - padding * 2, static_cast<float>(window.getSize().y) * 0.8f });
}

void Portfolio::setupTitle()
{
	title.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	title.setFillColor(sf::Color::White);
	title.setString((*iter)->getTitle());
	Position::center(display, title);
	title.setPosition({ title.getPosition().x, static_cast<float>(window.getSize().y) * 0.8f + left.getRadius() / 2});
}

void Portfolio::updateTitle()
{
	title.setString((*iter)->getTitle());
}

void Portfolio::setupIter()
{
	iter = programs.begin();
}

void Portfolio::moveLeft()
{
	if(programs.size() > 1)
	{
		if (iter == programs.begin())
		{
			iter = programs.end();
		}
		else
		{
			iter--;
		}
		updateTitle();
	}
}

void Portfolio::moveRight()
{
	if (programs.size() > 1)
	{
		if (iter == programs.end())
		{
			iter = programs.begin();
		}
		else
		{
			iter++;
		}
		updateTitle();
	}
}
