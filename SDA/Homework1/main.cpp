/**
 *
 * Solution to homework task
 * Data Structures Course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Boyko Tsvetanov
 * @idnumber 61953
 * @task 1
 * @compiler VC
 *
 */
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<iomanip> // used to set precision
#include<vector>  // used to store operator objects (could've implemented a dynamic array)
#include "Stack.cpp" //.cpp because it's a template stack
#include "Opers.h"
using namespace std;

int main(int argc, char **argv)
{
	vector<Opers*> opers;
	string prim_niz = "";
	//First file is the prefix notation
	string tonotate(argv[1]);
	ifstream file1(tonotate);
	if (file1.peek() == std::ifstream::traits_type::eof())
	{
		// If file is empty
		cout << "Error" << endl;

	}
	else
	{
		if (file1.is_open())
		{
			getline(file1, prim_niz);
			file1.close();
		}
		else cout << "Can't open file" << endl;

		ifstream file2;
		file2.open(argv[2]);
		while (!file2.eof())
		{
			char symb, op, asoc;
			while (file2 >> symb >> op >> asoc)
			{
				opers.push_back(new Opers(symb, op, asoc));
			}
		}
		file2.close();
		//Helpers
		string _operator, _op1, _op2;
		float  _calcop1, _calcop2;
		//Variables used for validation check at the end
		int forcheck_numcount = 0;
		int forcheck_opcount = 0;
		bool hasProblem = false;
		Stack<string> stak(prim_niz.length());
		Stack<float> calc_stak(prim_niz.length());

		for (int i = prim_niz.length() - 1; i >= 0; i--)
		{
			if (isdigit(prim_niz.at(i)))
			{
				int temp = i;
				string duff = "";
				do
				{
					temp--;
				} while (prim_niz.at(temp) != ' ');
				for (int j = temp + 1; j <= i; j++)
				{
					//Making an area(multi-digit number) of single-digit numbers
					duff += prim_niz.at(j);
				}
				stak.push(duff);
				calc_stak.push(stof(duff));
				//One number is processed -> counter +=1
				forcheck_numcount += 1;
				i -= i - temp;
			}
			else if (prim_niz.at(i) == ' ')
			{
				continue;
			}
			else
			{
				//It's not a number, nor space => is an operation => opcounter +=1
				forcheck_opcount += 1;
				string buff = "";
				_operator = prim_niz.at(i);
				if (stak.isEmpty())
				{
					hasProblem = true;
					break;
				}
				else
				{
					_op1 = stak.top();
					stak.pop();
					if (stak.isEmpty())
					{
						hasProblem = true;
						break;
					}
					else
					{
						//Stack isn't empty
						_op2 = stak.top();
						stak.pop();
						buff = _op1 + " " + _op2 + " " + _operator;
						stak.push(buff);

						_calcop1 = calc_stak.top();
						calc_stak.pop();
						_calcop2 = calc_stak.top();
						calc_stak.pop();
						char char_op = _operator.at(0);
						for (size_t j = 0; j < opers.size(); j++)
						{
							//Until the symbol is found 
							if (opers.at(j)->getOp() == char_op)
							{
								//Calculating 
								calc_stak.push(opers.at(j)->Result(opers.at(j)->getSymb(), _calcop1, _calcop2));
								break;
							}
							else continue;
						}
					}
				}

			}
		}

		//Validations (numbers have to be more than the operators)
		if (forcheck_numcount <= forcheck_opcount&& hasProblem == false)
		{
			cout << "Error" << endl;
			hasProblem = true;
		}
		else if (hasProblem == true)
			cout << "Error" << endl;
		else
		{
			//Output
			do
			{
				cout << stak.top();
				stak.pop();
			} while (!stak.isEmpty());
			cout << endl << fixed << setprecision(5) << calc_stak.top() << endl;
		}
	}
	//Clearing dynamic memory allocated by vector "opers"
	opers.clear();
	cin.get();
	return 0;
}