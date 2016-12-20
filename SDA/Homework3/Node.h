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
#ifndef NODE_H
#define NODE_H
#include <vector>
using namespace std;

class Node {
public:
	Node();
	~Node();
	char content();
	void setContent(char);
	void setRating(int);
	bool wordMarker();
	void setWordMarker();
	int getRating();
	char getContent();
	Node* findChild(char);
	void appendChild(Node*);
	vector<Node*> children();
private:
	char _content;
	int _rating;
	bool _marker;
	vector<Node*> _children;
};

#endif // !NODE_H
