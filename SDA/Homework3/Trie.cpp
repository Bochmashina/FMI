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
#include "Trie.h"
Trie::Trie()
{
	root = new Node();
}
Trie::~Trie()
{
	delete root;
}
void Trie::addWord(Words& word)
{
	Node* current = root;
	int s_size = word.getContent().length();
	if (s_size == 0)
	{
		current->setWordMarker();
		return;
	}

	for (int i = 0; i < s_size; i++)
	{
		Node* child = current->findChild(word.getContent()[i]);
		if (child != NULL)
		{
			current = child;
		}
		else
		{
			Node* tmp = new Node();
			tmp->setContent(word.getContent()[i]);
			tmp->setRating(word.getRating());
			current->appendChild(tmp);
			current = tmp;
		}
		if (i == s_size - 1)
			current->setWordMarker();
	}
}
double Trie::searchInString(string str)
{
	double sumOfcoef = 0;
	int str_size = str.size();
	int spaces_count = 0;
	double num_words = 0;
	Node* current = root;
	//This for cycle counts the words, sums the ratings of the file and returns the file rating
	for (size_t i = 0,n=str.length(); i < n; i++)
	{
		
		if ((str[i] <= 64 || str[i] >= 123 || (str[i] >= 91 && str[i] <= 96)) && i != str_size - 1
			&& ((str[i + 1] >= 65 && str[i + 1] <= 90)|| (str[i + 1] >= 97 && str[i + 1] <= 122)))
		{
			spaces_count += 1;
			Node* temp = current->findChild(str[i]);
			if (temp != NULL)
			{
				if (temp->wordMarker() && (str[i + 1] <= 64 || str[i + 1] >= 123 || (str[i + 1] >= 91 && str[i + 1] <= 96)))
				{
					//word is found
					sumOfcoef += temp->getRating();
					current = root;
				}
				else
				{
					current = temp;
				}
			}
			else
			{
				current = root;
				continue;
			}
			continue;
		}
		else if ((str[i + 1] <= 64 || str[i + 1] >= 123 || (str[i + 1] >= 91 && str[i + 1] <= 96)) && i == str_size - 1)
		{
			Node* temp = current->findChild(str[i]);
			if (temp != NULL)
			{
				if (temp->wordMarker() && (str[i + 1] <= 64 || str[i + 1] >= 123 || (str[i + 1] >= 91 && str[i + 1] <= 96)))
				{
					//word is found
					sumOfcoef += temp->getRating();
					current = root;
				}
				else
				{
					current = temp;
				}
			}
			else
			{
				current = root;
				continue;
			}
			continue;
		}
		else if(str[i]>=65&&str[i]<=90)
		{
			str[i] = str[i] + 32;
			Node* temp = current->findChild(str[i]);
			if (temp != NULL)
			{
				if (temp->wordMarker() && (str[i + 1] <= 64 || str[i + 1] >= 123||(str[i+1]>=91&&str[i+1]<=96)))
				{
					//word is found
					sumOfcoef += temp->getRating();
					current = root;
				}
				else
				{
					current = temp;
				}
			}
			else
			{
				current = root;
				continue;
			}
		}
		else
		{
			Node* temp = current->findChild(str[i]);
			if (temp != NULL)
			{
				if (temp->wordMarker() && (str[i + 1] <= 64 || str[i + 1] >= 123 || (str[i + 1] >= 91 && str[i + 1] <= 96)))
				{
					//word is found
					sumOfcoef += temp->getRating();
					current = root;
				}
				else
				{
					current = temp;
				}
			}
			else
			{
				current = root;
				continue;
			}
		}
	}
	double temp_num_words = spaces_count + 1;
	num_words = temp_num_words;
	if (num_words == 0)
	{
		return 0;
	}
	else return sumOfcoef/num_words;
}