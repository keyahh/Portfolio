//
// Created by Dave R. Smith on 5/15/24.
//

#include "Term.h"

Term::Term()
{
}

Term::Term(double x)
{
	num = x;
}

Term::Term(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/'|| c == '^')
	{
		op = c;
	}
}

Term::Term(const std::string& str)
{
	if (checkIsNum(str))
		num = std::stod(str);
	else if (str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '^'))
		op = str[0];
}

bool Term::checkIsNum(const std::string& str)
{
	if (str.size() > 1 && str[0] == '-') //for negative numbers
	{
		return true;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void Term::setNum(double num)
{
	Term::num = num;
}

void Term::setOp(char op)
{
	Term::op = op;
}

const double Term::getNumber() const
{
	return num;
}

const char Term::getOp() const
{
	return op;
}

const bool Term::isNumber() const
{
	return num != NULL;
}

const bool Term::isOperator() const
{
	return op != '\0';
}

bool operator==(const Term& t1, const Term& t2)
{
	if (t1.num != NULL && t2.num != NULL)
		return t1.num == t2.num;
	
	if (t1.op != '\0' && t2.op != '\0')
		return t1.op == t2.op;
}

std::ostream& operator<<(std::ostream& cout, const Term& term)
{
	if (term.num != NULL)
		return cout << term.num << ' ';

	if (term.op != '\0')
		return cout << term.op << ' ';
}

std::istream& operator>>(std::istream& cin, Term& term)
{
	std::string temp;
	cin >> temp;
	if ((temp.size() == 1) && (temp[0] == '+' || temp[0] == '-' || temp[0] == '*' || temp[0] == '/' || temp[0] == '^'))
		term.op = temp[0];
	else if (std::stod(temp) * 0 == 0)
		term.num = std::stod(temp);

	return cin;
}