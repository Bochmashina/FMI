#pragma once
#ifndef OPERS_H
#define OPERS_H

class Opers
{
private:
	char symb, op, asoc; // Символът, който изобразява операцията и съответно операцията, която му съответства
public:
	Opers();
	Opers(char, char, char);
	float Result(char, float, float);
	char getOp();
	char getSymb();
	char getAsoc();
	void setOp(char);
	void setSymb(char);
	void setAsoc(char);
};
#endif // !"OPERS_H"
