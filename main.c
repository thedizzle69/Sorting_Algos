//#pragma warning(disable:4996) //Visual Studio warning disable (scanf is unsecure)


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "mainMenu.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "standardFunctions.h"
#include "sorts.h"
#include "nodes.h"

int main() {

	srand(time(NULL)); //setup for random integer (has to be in main func, else get_random_integer will put out only the same number while compiling)

	cls();

	//endless loop for main menu
	while (1) {

		switch (mainMenu()) { //open the main menu and evaluate the return (input)
		case 1: 
			task1();
			break;
		case 2: 
			task2();
			break;
		case 3: 
			task3();
			break;
		case 4: 
			task4();
			break;
		case 5: //Exit
			return 1;
		default: //Error
			printf("I think this can never happen as there is an error catch in the Main Menu.\n");
			break;
		}

		return 0;

	}

}

