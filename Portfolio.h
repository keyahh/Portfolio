#ifndef PORTFOLIOH
#define PORTFOLIOH

#include "Program.h"
#include "Helper/Button.h"
#include <vector>

class Portfolio
{
    sf::RenderWindow window;
    sf::RenderTexture texture;
    sf::Sprite display;
    sf::Text title;
    sf::Event event;
    sf::Clock clock;

    std::vector<Program*> programs;
    std::vector<Program*>::iterator iter;

    float padding = 100.f, dt = 0.f;

    Button left, right;

    void init();
    void setupDisplay();
    void setupButtons();
    void setupTitle();
    void setupIter();
    void moveLeft();
    void moveRight();
    void updateTitle();

public:
    Portfolio(sf::VideoMode videoMode = { 1920, 1080 }, std::string windowName = "Portfolio");
    void run();
    void addProgram(Program& program);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void render();
};

#endif