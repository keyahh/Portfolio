//
// Created by Dave R. Smith on 5/15/24.
//

#ifndef CS3A_SPRING24_RPN_INVALIDPOSTFIXEXPRESSIONEXCEPTION_H
#define CS3A_SPRING24_RPN_INVALIDPOSTFIXEXPRESSIONEXCEPTION_H

#include <exception>

class InvalidPostfixExpressionException : public std::exception
{
public:
	const char* what() const;
};


#endif //CS3A_SPRING24_RPN_INVALIDPOSTFIXEXPRESSIONEXCEPTION_H
