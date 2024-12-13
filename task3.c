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

void task3() {

    cls();
    printf("Task 3: Bubblesort * 20:\n\n");

    int* arrPtrs[1];
    int arraySize[1] = { 2000 };
    float timer[20]; //7 array sizes times 4 algorithms

    int* tempArray;

    unsigned int i; //thats unsigned because of Wextra
    int j, k = 0;

    //clear timer array
    for (i = 0; i < 20; i++) {
        timer[i] = 0;
    }

    for (i = 0; i < sizeof(arrPtrs) / sizeof(arrPtrs[0]); i++) {
        arrPtrs[i] = generate_array(arraySize[i]);
    }

    for (i = 0; i < 20; i++) {
        tempArray = (int*)calloc(arraySize[k], sizeof(int)); //reserver Memory for the temp Array
        if (tempArray == 0) { //Error check if calloc couldnt reserve Memory
            printf("Error: Couldnt reserve Memory!\n");
            wait_for_enter();
            return;
        }

        //copy the random array from arrPtrs to tempArray
        for (j = 0; j < arraySize[k]; j++) {
            tempArray[j] = *(arrPtrs[k] + j);
        }

        timer[i] = clock();
        bubble_sort(tempArray, arraySize[k]);
        timer[i] = ((double)clock() - timer[i]) / CLOCKS_PER_SEC;
        printf("Run %d: %fs\n", i + 1, timer[i]);

        //if k == the Elements of arrPtrs (amount of arrays) - 1
        if (k == sizeof(arrPtrs) / sizeof(arrPtrs[0]) - 1) {
            k = 0;
        }
        else {
            k++;
        }

        free(tempArray);
    }

    printf("Timer max: %fs\n", timer_max(timer, 20));
    printf("Timer min: %fs\n", timer_min(timer, 20));
    printf("Timer avg: %fs\n", timer_avg(timer, 20));

    wait_for_enter();

    for (i = 0; i < sizeof(arrPtrs) / sizeof(arrPtrs[0]); i++) {
        free(arrPtrs[i]);
    }

    return;
}