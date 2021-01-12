#pragma once
#include "Item.h"
using namespace std;

class ArrayList
{

public:
	ArrayList()
	{
		size = 0;
		list = new int[0];
	}

	ArrayList(int d)
	{
		size = 0;
		list = new int[d];
	}

	bool contains(int d)
	{
		bool find = false;
		for (int i = 0; i < size; i++)
		{

			if (list[i] == d)
			{
				find = true;
				break;
			}
		}
		return find;
	}

	ArrayList(int length, int *l)
	{
		size = length;
		list = l;
	}

	//public int remove (int) : removes an element given at the specified index

	int remove(int index)
	{

		int removed = -1;

		if (checkIndex(index))
		{

			removed = list[index];

			int *l = new int[size - 1];

			for (int i = 0; i < size; i++)
			{

				if (i >= index)
				{
					l[i] = list[i + 1];
				}
				else
				{

					l[i] = list[i];
				}
			}

			list = l;
			size -= 1;
		}
		else
		{

			cout << "Index Out of bound\n";
		}
	}

	//Checks if the arraylist is empty or not
	bool isEmpty()
	{

		if (size == 0)
		{

			return true;
		}
		else
		{

			return false;
		}
	}

	//clears the arryList
	void clear()
	{
		delete list;

		list = new int[0];
		size = 0;
	}

	//public void add(int data) : adds the given element at the specified index

	void add(int item)
	{

		//int *l = new int[size + 1];	for(int i = 0; i < size; i++){	l[i] = list[i];

		//}

		//
		list[size] = item;
		size++; //for(int i = 0; i < size; i++){	list[i] = l[i];
	}

	//list = l;	size ++;	list[size - 1] = d;	}

	//public int get(int index) : returns the element at the specified index

	int get(int index)
	{

		if (checkIndex(index))
		{

			return list[index];
		}

		else
		{

			cout << "Index Out of bounds" << endl;
		}
	}

	// pubkic int length() : returns the length of the ArrayList at current time :

	int length() const { return size; }

	//returns a new copy of the arraylist
	ArrayList clone()
	{

		return ArrayList(length(), list);
	}

	~ArrayList()
	{
		delete[] list;
		list = NULL;
	}

private:
	int size;
	int *list;

	//private bool checkIndex(int index) : checks the index is not out of bounds :

	bool checkIndex(int index)
	{

		bool right = false;
		if (index >= 0 && index < size)
		{

			right = true;
		}
		else
		{
			right = false;
		}
		return right;
	}
};