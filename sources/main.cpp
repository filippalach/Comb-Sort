//This is main.cpp main application source file

#include <iostream>
#include "functions.h"

int main()
{
	node *H=NULL;

	uploadToFile();
	loadFromFile(H,"DataSet.txt");
	showList(H);
	combSort(H);
	showList(H);

	return 0;
}

