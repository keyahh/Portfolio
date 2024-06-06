#ifndef CALCPROG
#define CALCPROG

#include "Program.h"
#include "Calculator/Calculator.h"

class CalculatorProgram : public Program
{
private:
    Calculator c;

public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event, float dt, int pad);
    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual std::string getTitle() const;
};


#endif // !CALCPROG

