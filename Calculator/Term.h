//
// Created by Dave R. Smith on 5/15/24.
//

#ifndef CS3A_SPRING24_RPN_TERM_H
#define CS3A_SPRING24_RPN_TERM_H

#include <iostream>
#include <string>

class Term
{
private:
	double num = NULL;
	char op = '\0';

	bool checkIsNum(const std::string& str);

public:
	Term();
	Term(double x);
	Term(char x);
	Term(const std::string& str);

	void setNum(double num);
	void setOp(char op);
	const double getNumber() const;
	const char getOp() const;
	const bool isNumber() const;
	const bool isOperator() const;

	friend bool operator==(const Term& t1, const Term& t2);
	friend std::ostream& operator<<(std::ostream& cout, const Term& term);
	friend std::istream& operator>>(std::istream& cin, Term& num);
};


#endif //CS3A_SPRING24_RPN_TERM_H
