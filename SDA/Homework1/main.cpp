#include<iostream>
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
	string prim_niz = { "c d 8 5 b f 20 4 e d 5 8 10" };
	string prim_prav = { "a + 1 b + 1 c - 1 d * 1 e / 0 f / 1" };
	Opers oper;
	Stack<char> stak(prim_niz.length());
	string output = "";
	for (int i = prim_niz.length()-1;i>0; i--)
	{
		if (prim_niz.at(i) >= 48 && prim_niz.at(i) <= 57) // Ако е цифра
		{
			stak.push(prim_niz.at(i));
			cout << "Pushed" << stak.top() << endl;
		}
		else if (prim_niz.at(i) == ' ')					  //Ако е празно място
		{
			cout << "shpacq" << endl; //TODO
		}
		else cout << "operatori" << endl; //TODO
	}


	cin.get();

	return 0;
}