//This is main.cpp main application source file

#include <iostream>
#include "functions.h"

int main()
{
	node *H=NULL;

	pushFront(H,1);
	pushFront(H,2);
	pushFront(H,3);
	pushFront(H,1);
	pushFront(H,11);
	pushFront(H,3);

	showList(H);

	return 0;
}

