#ifndef CS3A_SPRING24_RPN_POSTFIX_H
#define CS3A_SPRING24_RPN_POSTFIX_H

#include "Term.h"
#include <vector>
#include <sstream>

class Postfix
{
private:
	std::vector<Term> terms;
	bool isNumber(const std::string& str);
	int numCount = 0, opCount = 0;

public:
	Postfix();
	Postfix(const std::string& equation);

	const std::vector<Term>::const_iterator cbegin() const;
	const std::vector<Term>::const_iterator cend() const;

	const bool isValid() const;

	friend std::istream& operator>>(std::istream& cin, Postfix& postfix);
	friend std::ostream& operator<<(std::ostream& cout, const Postfix& postfix);
};


#endif //CS3A_SPRING24_RPN_POSTFIX_