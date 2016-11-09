#pragma once
#ifndef STACK_H
#define STACK_H
template <class T>
class Stack
{
private:
	int size;
	T *values;
	int index;
public:
	Stack();
	Stack(int);
	~Stack();

	void pop();
	void push(const T&);
	T& top();
	bool isEmpty();
};
#endif // !STACK_H
