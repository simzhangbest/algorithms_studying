#include <iostream>
#include "LinkList.h"
using namespace std;
using namespace SimLib;
int main()
{
	LinkList<int> list;

	for (size_t i = 0; i < 5; i++)
	{
		list.insert(0, i);
	}

	cout << list.find(0) << endl;


	return 0;
	

}