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
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<math.h>
#include "Trie.h"
using namespace std;

int main(int argc, char* argv[])
{
	Trie* trie = new Trie();
	//Dictionary ->
	string prim_niz(argv[1]);
	ifstream file1(prim_niz);
	while (!file1.eof())
	{
	if (file1.peek() == std::ifstream::traits_type::eof())
	{
		// If file is empty
		cout << 0 << endl;

	}
	else
	{
		if (file1.is_open())
		{
			string content;
			int rating = 0;
			while (getline(file1, content))
			{
				int line_size = content.size();
				string int_str = "";
				for (int i = line_size-1; i > 0; i--)
				{
					//Getting the size of the rating 
					if (content[i] != ' ')
					{
						int_str += content[i];
					}
					else break;
				}
				int int_str_size = int_str.size();
				for (int i = 0; i < int_str_size; i++)
				{ 
					//Transforming the reversed integer into the rating we need
					if(i==int_str_size-1)
						if (int_str[i] == '-')
						{
							rating = 0 - rating;
						}
						else 
						{
							rating += (int_str[i] - '0') * (pow(10, i));
						}
					else rating += (int_str[i] - '0') * (pow(10, i));
					
				}
				//Getting the size of the phrase in the dictionary
				int content_size = line_size - int_str_size;
				//This do-while cycle gets rid of the whitespaces between the phrase and the rating
				do
				{
						content_size -= 1;
				} while (content[content_size] == ' ');
				content_size += 1;
				//The phrase is substracted from the whole string
				content = content.substr(0, content_size);
				//Phrase + rating is added in tree
				trie->addWord(Words(content, rating));
				rating = 0;

			}
			file1.close();
		}
		else cout << "Can't open file" << endl;
	}

}
	file1.close();
	//Dictionary is ready. Reading the texts ->

	for (int i = 2; i < argc; i++)
	{
		double fileRating = 0.0;
		string prim_niz2(argv[i]);
		ifstream file2(prim_niz2);
		while (!file2.eof())
		{
			if (file2.peek() == std::ifstream::traits_type::eof())
			{
				// If file is empty
				cout << 0 << endl;

			}
			else
			{
				if (file2.is_open())
				{
					string line = "";
					double temp_file_rating = 0;
					//If the file is HUGE, this will cause a problem - This will get the line of the whole file, which has 
					//O(n) difficulty. To avoid this, this can be reviewed in chunks, but then if a phrase is split between
					//two chunks, it will be difficult to trace the size of that phrase. \r treats the text as one row.

					while (getline(file2, line, '\r'))
					{
						temp_file_rating += trie->searchInString(line);
						fileRating += temp_file_rating;
						temp_file_rating = 0;
					}
					file2.close();
					//Output
					cout << prim_niz2<<" "<<fileRating << endl;
				}
				else cout << "Can't open file" << endl;
			}

		}
	}
	delete trie;
	return 0;
}