#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<vector>
#include "Stack.cpp"
#include "Opers.h"
using namespace std;

int main(int argc, char **argv)
{
	//string prim_niz1 = { "c d 8 5 b f -25.210 4 e d 5 8 10" };
	//string prim_prav = { "a + 1 b + 1 c - 1 d * 1 e / 0 f / 1" };
	string prim_niz="";
	//string prim_prav = "";
	string tonotate(argv[1]);
	ifstream file1(tonotate);
	if (file1.is_open())
	{
		getline(file1, prim_niz);
		file1.close();
	}
	else cout << "Can't open file" << endl;

	ifstream file2;
	file2.open(argv[2]);

	vector<Opers*> opers;
	while (!file2.eof())
	{
		char symb, op, asoc;
		while (file2 >> symb >> op >> asoc)
		{
			opers.push_back(new Opers(symb, op, asoc));
		}
	}
	file2.close();
	string _operator, _op1, _op2;

	Stack<string> stak(prim_niz.length());
	Stack<float> calc_stak(prim_niz.length());


	for (int i = prim_niz.length()-1;i>=0; i--)
	{
		if (isdigit(prim_niz.at(i)))
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

		
			i -= i - temp;
			}
		else if (prim_niz.at(i) == ' ')
		{
			continue;
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