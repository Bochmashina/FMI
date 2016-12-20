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
#pragma once
#ifndef WORDS_H
#define WORDS_H
#include<string>
using namespace std;
//This class is used to get control of the content and rating of the words in the dictionary
class Words {

private:
	string _content;
	int _rating;
public:
	Words();
	~Words();
	Words(string, int);
	string getContent();
	int getRating();
};

#endif // !WORDS_H
