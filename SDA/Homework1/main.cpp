#include<iostream>
#include<string>
#include<stdio.h>
#include "Stack.cpp"
#include "Opers.h"
using namespace std;
/*void PrefixToPostfix(string a, string b)
{
	char temp, operand1, operand2;
}
*/
int main()
{
	string prim_niz = { "c d 8 5 b f -25.210 4 e d 5 8 10" };
	string prim_prav = { "a + 1 b + 1 c - 1 d * 1 e / 0 f / 1" };
	Opers oper;
	string _operator, _op1, _op2;  //Буферни променливи	
	Stack<string> stak(prim_niz.length());
	string output = "";
	for (int i = prim_niz.length()-1;i>=0; i--)
	{
		if (isdigit(prim_niz.at(i))) // Ако е цифра
		{
			int temp = i;
			string duff = "";
			do
			{
				temp--;
			} while (prim_niz.at(temp)!= ' ');
			for (int j = temp + 1; j <= i; j++)
			{
				
				duff += prim_niz.at(j);
			}
			stak.push(duff);
			cout << "Multiple pushed " << duff << endl;
			i -= i - temp;
				/*	for (int i = prim_niz.length()-1;i>=0; i--)
	{
		if (isdigit(prim_niz.at(i))) // Ако е цифра
		{
				if (isdigit(prim_niz.at(i - 1)))
				{
					string buff = "";
					string s1(1, prim_niz.at(i));
					string s2(1, prim_niz.at(i - 1));
					buff = s2 + s1;
					stak.push(buff);
					cout << "PUSHEDDD " << buff << endl;
					i--;
				}
				else if (prim_niz.at(i - 1) == ' ')
				{
					string s(1, prim_niz.at(i));
					stak.push(s);
				}
				else continue;
				}
		else if (prim_niz.at(i) == ' ')					  //Ако е празно място
		{
			continue;//TODO
		}
		else
		{
			string buff = "";
			_operator = prim_niz.at(i);
			_op1 = stak.top();
			stak.pop();
			_op2 = stak.top();
			stak.pop();
			buff = _op1 + " " + _op2 + " " + _operator;
			stak.push(buff);
		}
	}*/
			}
		else if (prim_niz.at(i) == ' ')					  //Ако е празно място
		{
			continue;//TODO
		}
		else
		{
			string buff = "";
			_operator = prim_niz.at(i);
			_op1 = stak.top();
			stak.pop();
			_op2 = stak.top();
			stak.pop();
			buff = _op1 + " " + _op2 + " " + _operator;
			stak.push(buff);
		}
	}
	do
	{
		cout << stak.top();
		stak.pop();
	} while (!stak.isEmpty());
	cin.get();
	return 0;
}