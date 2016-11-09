#pragma once
#ifndef OPERS_H
#define OPERS_H

class Opers
{
private:
	char symb, op; // Символът, който изобразява операцията и съответно операцията, която му съответства
public:
	Opers();
	float Result(float, float);
	char getOp();
	char getSymb();
	void setOp(char);
	void setSymb(char);
};
#endif // !"OPERS_H"
