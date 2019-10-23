#include <iostream>
#include "DynamicList.h"
#include "StaticArray.h"
using namespace std;
using namespace SimLib;
int main()
{
	StaticArray<int, 5> sl;
	
	for (int i = 0; i < sl.length(); i++)
	{
		sl[i] = i * i;
	}

	for (int i = 0; i < sl.length(); i++)
	{
		cout << sl[i] << endl;
	}

	sl[6] = 11;

	

}