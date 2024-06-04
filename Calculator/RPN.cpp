#include "RPN.h"

bool RPN::isNumber(const Term& term)
{
    return term.isNumber();
}

bool RPN::isOperator(const Term& term)
{
    return term.isOperator();
}


const Term RPN::evalutate(std::stack<Term>& stack, const Term& term)
{
    double b = stack.top().getNumber();
    stack.pop();
    double a = stack.top().getNumber();
    stack.pop();

    switch (term.getOp())
    {
    case '+':
        return Term(a + b);
        break;
    case '-':
        return Term(a - b);
        break;
    case '*':
        return Term(a * b);
        break;
    case '/':
        return Term(a / b);
        break;
    case '^':
        return Term(pow(a, b));
        break;
    case '%':
        return Term(fmod(a, b));
        break;
    default:
        return Term();
    }
}

Term RPN::evaluate(const Postfix& equation)
{
    std::stack<Term> stack;
    try {
        if (equation.isValid())
        {
            auto iter = equation.cbegin();
            for (; iter != equation.cend(); ++iter)
            {
                if (isNumber(*iter))
                {
                    stack.push(*iter);
                }
                else if (isOperator(*iter))
                {
                    stack.push(evalutate(stack, *iter));
                }
            }
            return stack.top();
        }
        else
        {
            throw InvalidPostfixExpressionException();
        }
    }
    catch (InvalidPostfixExpressionException invalidPFE)
    {
        std::cout << invalidPFE.what();
        return Term();
    }
}