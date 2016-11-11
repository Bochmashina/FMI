#include "Opers.h"
using namespace std;
Opers::Opers()
{}
Opers::Opers(char symb, char op, char asoc)
{
	setOp(symb);
	setSymb(op);
	setAsoc(asoc);
}
char Opers::getOp()
{
	return this->op;
}
char Opers::getSymb()
{
	return this->symb;
}
char Opers::getAsoc()
{
	return this->asoc;
}
void Opers::setOp(char op)
{
	this->op = op;
}
void Opers::setSymb(char symb)
{
	this->symb = symb;
}
void Opers::setAsoc(char asoc)
{
	this->asoc = asoc;
}

float Opers::Result(float a, float b)
{
	if (getOp() == '+')
		return a + b;
	else if (getOp() == '-')
		return a - b;
	else if (getOp() == '*')
		return a*b;
	else if(getOp() =='/')
	return a / b;
	else return 0;
}
