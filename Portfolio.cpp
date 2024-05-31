#include "Portfolio.h"


Portfolio::Portfolio(sf::VideoMode videoMode, std::string windowName)
{
	window.create(videoMode, windowName);
	init();
}

void Portfolio::run()
{
	while (window.isOpen())
	{
		eventHandler(window, event);

		dt = clock.restart().asSeconds();

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

		if (MouseEvents::isClicked(left, window))
		{
			moveLeft();
		}
		if (MouseEvents::isClicked(right, window))
		{
			moveRight();
		}
	}
}

void Portfolio::render()
{
	window.clear();

	window.draw(left);
	window.draw(right);
	window.draw(title);
	window.draw(*(*iter));
}

void Portfolio::init()
{
	setupIter();
	setupDisplay();
	setupButtons();
	setupTitle();
}

void Portfolio::setupDisplay()
{



}

void Portfolio::setupButtons()
{
	left.setPosition({padding, static_cast<float>(window.getSize().y) * 0.8f});
	right.setPosition({ static_cast<float>(window.getSize().x) - padding, static_cast<float>(window.getSize().y) * 0.8f });
}

void Portfolio::setupTitle()
{
	title.setString((*iter)->getTitle());
}

void Portfolio::setupIter()
{
	iter = programs.begin();
}

void Portfolio::moveLeft()
{
	if (iter == programs.begin())
	{
		iter = programs.end();
	}
	else
	{
		iter--;
	}

	setupTitle();
}

void Portfolio::moveRight()
{
	if (iter == programs.end())
	{
		iter = programs.begin();
	}
	else
	{
		iter++;
	}

	setupTitle();
}
