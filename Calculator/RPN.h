//
// Created by Dave R. Smith on 5/15/24.
//

#ifndef CS3A_SPRING24_RPN_RPN_H
#define CS3A_SPRING24_RPN_RPN_H

#include <stack>
#include "InvalidPostfixExpressionException.h"
#include "Postfix.h"
class RPN
{
private:
    static bool isNumber(const Term& term);
    static bool isOperator(const Term& term);
    static const Term evalutate(std::stack<Term>& stack, const Term& term);

public:
    static Term evaluate(const Postfix& equation);
};


#endif //CS3A_SPRING24_RPN_RPN_H
