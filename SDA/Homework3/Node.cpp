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
#include "Node.h"
using namespace std;
	Node::Node()
	{
		_content = ' ';
		_marker = false;
	}
	Node::~Node()
	{
		_children.clear();
	}
	char Node::content() 
	{
		return _content;
	}
	void Node::setContent(char c)
	{
		_content = c;
	}
	bool Node::wordMarker()
	{
		return _marker;
	}
	void Node::setWordMarker() 
	{
		_marker = true;
	}
	int Node::getRating()
	{
		return this->_rating;
	}
	char Node::getContent()
	{
		return this->_content;
	}
	Node* Node::findChild(char c)
		{
		int mChildren_size = _children.size();
			for (int i = 0; i < mChildren_size; i++)
			{
				Node* temp = _children.at(i);
				if (temp->content() == c)
				{
					return temp;
				}
			}

			return NULL;
		}
	void Node::appendChild(Node* child) 
	{
		_children.push_back(child);
	}
	vector<Node*> Node::children() 
	{
		return _children; 
	}
	void Node::setRating(int rating)
	{
		this->_rating = rating;
	}