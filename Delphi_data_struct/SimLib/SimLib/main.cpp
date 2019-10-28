#include <iostream>
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
using namespace std;
using namespace SimLib;
int main()
{

	DynamicArray<int> sla(8);
	for (int i = 0; i < sla.length(); i++)
	{
		sla[i] = i * i;
	}
	for (int i = 0; i < sla.length(); i++)
	{
		cout << sla[i] << endl;
	}

	cout << "---------" << endl;
	DynamicArray<int> sla2(10);

	sla2 = sla;


	for (int i = 0; i < sla2.length(); i++)
	{
		cout << sla2[i] << endl;
	}


	return 0;
	

}