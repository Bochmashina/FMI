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
#ifndef TRIE_H
#define TRIE_H
#include "Node.h"
#include "Words.h"
#include<string>
using namespace std;
/*
The general idea for this kind of tree (using vector),
I found in http://www.sourcetricks.com/2011/06/c-tries.html#.WFlKUhuLTIU
There would be a problem with large files (because of the vector). That's why
it's a better practice to use char[27]. Estimated time  when tested with 1 MB .txt file is 5-6 seconds.
*/
class Trie {
public:
	Trie();
	~Trie();
	void addWord(Words&);
	double searchInString(string);

private:
	Node* root;
};

#endif // !TRIE_H


//------------------------------------------------------------------------------------------------------------//

