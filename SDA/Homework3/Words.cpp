/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Boyko Tsvetanov
* @idnumber 61953
* @task 3
* @compiler VC
*
*/
#include "Words.h"
Words::Words()
{
	this->_content = "";
	this->_rating = 0;
}
Words::~Words(){}
Words::Words(string content, int rating)
{
	this->_content = content;
	this->_rating = rating;
}
string Words::getContent()
{
	return this->_content;
}
int Words::getRating()
{
	return this->_rating;
}