#include "Postfix.h"

Postfix::Postfix()
{

}

Postfix::Postfix(const std::string& equation)
{
	std::string temp = equation;

	while (temp.back() == ' ')
	{
		temp.pop_back();
	}

	std::stringstream ss;
	ss << temp;

	while (!ss.eof())
	{
		ss >> temp;
		terms.push_back(Term(temp));
	}

	for (auto& t : terms)
	{
		if (t.isNumber())
			numCount++;
		else
			opCount++;
	}
}

bool Postfix::isNumber(const std::string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

const std::vector<Term>::const_iterator Postfix::cbegin() const
{
	return terms.cbegin();
}

const std::vector<Term>::const_iterator Postfix::cend() const
{
	return terms.cend();
}

const bool Postfix::isValid() const
{
	if (numCount <= 0 || numCount <= opCount || opCount <= 0)
	{
		return false;
	}
	return true;
}

std::istream& operator>>(std::istream& cin, Postfix& postfix)
{
	std::string temp;
	cin >> temp;
	postfix.terms.push_back(Term(temp));
	return cin;
}

std::ostream& operator<<(std::ostream& cout, const Postfix& postfix)
{
	for (int i = 0; i < postfix.terms.size(); i++)
	{
		cout << postfix.terms[i];
	}
	return cout;
}