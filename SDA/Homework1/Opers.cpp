#include "Opers.h"
using namespace std;
Opers::Opers()
{}
char Opers::getOp()
{
	return this->op;
}
char Opers::getSymb()
{
	return this->symb;
}
void Opers::setOp(char op)
{
	this->op = op;
}
void Opers::setSymb(char symb)
{
	this->symb = symb;
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
