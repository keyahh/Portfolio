//
// Created by Dave R. Smith on 5/15/24.
//

#include "InvalidPostfixExpressionException.h"

const char* InvalidPostfixExpressionException::what() const
{
    return "Invalid post fix expression";
}
