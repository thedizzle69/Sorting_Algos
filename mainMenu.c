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

int mainMenu() {
    int menu_input_int = 0;

    cls();

    while (1) {
        char menu_input_char[2];
        printf("Please Enter the Task you want:\n\n");
        printf("1) Task 1 / Base Implementation\n");
        printf("2) Task 2 / Runtime Comparison\n");
        printf("3) Task 3 / Bubblesort * 20\n");
        printf("4) Task 4 / Insertions Sort with Lists\n");
        printf("5) Exit\n");

        fgets(menu_input_char, 2, stdin);
        sscanf(menu_input_char, "%d", &menu_input_int);

        if (menu_input_int > 0 && menu_input_int < 6) {
          //error check if the input is a number between 1 and 5

        return menu_input_int;
        }
        else {
            printf("\nError: Please enter a valid number!\n");

        }

    }

}
