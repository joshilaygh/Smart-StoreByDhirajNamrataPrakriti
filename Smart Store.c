#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

const int minQ=5;

#include "structProduct.c"
#include "mainMenu.c"
#include "display.c"
#include "login.c"
#include "getProductDate.c"

int main()
{
	bool logStatus=false;
	userLogin(&logStatus);
	
	if (logStatus){
		mMenu();
	}
	return 0;
}
