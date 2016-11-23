// mytest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include "ShowTypeTraits.h"


int main()
{
	typedef function<bool(int, int)> type;
	ShowTypeTraitsHelper helper;
	helper.show2<type>();

	printf("press any key to exit...\n");
	_getch();
	return 0;
}

