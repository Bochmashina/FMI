#include "Stack.h"
#include "Operations.h"
#include "DynamicArray.h"
#include <iostream>
#include<fstream>
#include <string>
#include <cstring>
using namespace std;

//helper functions
bool isOperand(char c);
bool isOperator(char c, DynamicArray<Operation*> *op);
char findOperator(char c, DynamicArray<Operation*> *op);
int main()
{
    //operators are held in a dynamic array
    DynamicArray<Operation*> *oper = new DynamicArray<Operation*>;

   //load prefix notation
    std::string workstr;
    ifstream prefix_notation;
    prefix_notation.open("prefix.txt");
    getline(prefix_notation,workstr,'\n');
    cout<<workstr<<endl;

    size_t sizeofw = workstr.length();
    cout<<"size of workstr is "<<sizeofw<<endl;

    prefix_notation.close();
    char sign;
    //result from calculating
    float result;
     Stack<float> res(10);

    // numbers and intermediate results are held in stack
    Stack<std::string> st(sizeofw);


    //load operators
    ifstream oper_loader;
    oper_loader.open("operators.txt");
    while(oper_loader.eof() != true)
    {
        char code,sign,asoc;
         while(oper_loader>>code>>sign>>asoc)
        {
            oper->append(new Operation(code,sign,asoc));
            cout<<"pliok "<<code<<" "<<sign<<" "<<asoc<<endl;
        }


    }
    oper_loader.close();


//prefix to postfix

for(int cnt = sizeofw-1; cnt >= 0; cnt--)
{
    cout<<"loop "<<cnt<<endl;
    if(workstr.at(cnt) == 32)
    {
        cout<<"found space "<<endl;
        continue;
    }
    if (isOperator( workstr.at(cnt), oper))
    {
        cout<<"found operator "<<workstr.at(cnt)<<endl;
        std::string op1,op2,temp;
        op1 = st.Top(); st.Pop();
        op2 = st.Top(); st.Pop();
        temp = op1 + " " + op2 + " " + workstr.at(cnt);
        st.Push(temp);
        cout<<temp<<endl;

        sign = findOperator(workstr.at(cnt),oper);

        float num1 = res.Top(); res.Pop();
        float num2 = res.Top(); res.Pop();
        float tempnum;
        switch(sign)
        {
            case '+': tempnum = num1 + num2; res.Push(tempnum); break;
            case '-': tempnum = num1 - num2; res.Push(tempnum); break;
            case '*': tempnum = num1 * num2; res.Push(tempnum); break;
            case '/': tempnum = num1 / num2; res.Push(tempnum); break;
        }


    }
    else if( isOperand(workstr.at(cnt)) )
    {
        cout<<"found number "<<workstr.at(cnt)<<endl;
        if(workstr.at(cnt-1) == ' ')
        {
            std::string temp = "";
            temp=workstr.at(cnt);
            st.Push(temp);
            float num = atof(temp.c_str());
            res.Push(num);
            cout<<temp<<endl;
           // cnt--;
        }
        else
        {
            int from = cnt, to=cnt;
            std::string temp = "";
            while(workstr.at(cnt-1) != 32)
               {
                   to--;
                   cnt--;
                }
            for(int i = to; i <= from; i++)
            {
                temp+=workstr.at(i);
            }
            st.Push(temp);
            float num = atof(temp.c_str());
            res.Push(num);
            cnt = to;
        }
    }
}

//print postfix notation
result = res.Top();
cout<<st.Top()<<endl;
cout<<result<<endl;

delete  oper;
return 0;
}

bool isOperand(char c)
{
    if(c >= 48 && c <= 57)
        return true;
    else return false;
}
bool isOperator(char c, DynamicArray<Operation*> *op)
{
    for(int i = 0; i<= ((op->getSize())-1); i++ )
        {
            if(c == op->get(i)->getCode() )
            {return true;}
        }
    return false;
}

char findOperator(char c, DynamicArray<Operation*> *op)
{
    for(int i = 0; i<= ((op->getSize())-1); i++ )
        {
            if(c == op->get(i)->getCode() )
            {return op->get(i)->getOperation() ;}
        }
}
