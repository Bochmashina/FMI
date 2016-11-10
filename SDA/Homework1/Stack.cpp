#include "assert.h"
#include "Stack.h"
template <class T>
Stack<T>::Stack()
{
	this->size = 15;
	this->values = new T[size];
	this->index = -1;
}
template <class T>
Stack<T>::~Stack()
{
	delete[] values;
}
template <class T>
Stack<T>::Stack(int x)
{
	this->size = x;
	this->values = new T[size];
	this->index = 0;
}

template <class T>
void Stack<T>::pop()
{
	assert(!isEmpty());
	index --;
}
template <class T>
void Stack<T>::push(const T& in)
{
	values[index] = in;
	index += 1;
	
}
template <class T>
T& Stack<T>::top()
{
	assert(!isEmpty());
	return values[index-1];
}
template <class T>
bool Stack<T>::isEmpty()
{
	if (this->index == 0)
	return 1;
	else return 0;
}
template<class T>
int Stack<T>::getIndex()
{
	return this->index;
}