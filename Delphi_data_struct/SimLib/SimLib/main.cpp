﻿#include <iostream>
#include "LinkList.h"
using namespace std;
using namespace SimLib;
int main()
{
	LinkList<int> list;

	for (size_t i = 0; i < 5; i++)
	{
		list.insert(i);
	}

	for (size_t i = 0; i < 5; i++)
	{
		list.set(i, i*i);
	}

	for (size_t i = 0; i < list.length(); i++)
	{
		int v = 0;
		list.get(i, v);
		cout << v << endl;
	}

	for (size_t i = 0; i < list.length(); i++)
	{
		cout << list.get(i) << endl;
	}

	cout << "-------------------------" << endl;
	list.remove(2);

	for (size_t i = 0; i < list.length(); i++)
	{
		cout << list.get(i) << endl;
	}


	return 0;
	

}