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

void task2() {

	cls();
	printf("Task 2: Runtime Comparison:\n\n");

	int* arrPtrs[7];
	int arraySize[7] = { 8, 32, 128, 512, 2048, 8192, 32768};
	float timer[28] = { 0 }; //7 array sizes times 4 algorithms

	int* tempArray;

	unsigned i; //thats unsigned because of Wextra
	int j, k = 0; //running from 0 to the elements of arrPtrs (used for arrPtrs[k] and arraySize[k]

	//clear timer array
	for (i = 0; i < 28; i++) {
		timer[i] = 0;
	}

	//generate the 7 random arrays that will get sorted
	for (i = 0; i < sizeof(arrPtrs) / sizeof(arrPtrs[0]); i++) {
		arrPtrs[i] = generate_array(arraySize[i]);
	}

	for (i = 0; i < 28; i++) {
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

		//for i 0-6 use insertion sort
		if (i <= 6) {
			timer[i] = clock();
			insertion_sort(tempArray, arraySize[k]);
			timer[i] = ((double)clock() - timer[i]) / CLOCKS_PER_SEC;
			printf("Run %d: %fs\n", i + 1, timer[i]);
		}
		//for i 7-13 use bubble sort
		else if (i >= 7 && i <= 13) {
			timer[i] = clock();
			bubble_sort(tempArray, arraySize[k]);
			timer[i] = ((double)clock() - timer[i]) / CLOCKS_PER_SEC;
			printf("Run %d: %fs\n", i + 1, timer[i]);
		}
		//for i 14-20 use merge sort
		else if (i >= 14 && i <= 20) {

			int* tempArrMerge = (int*)calloc(arraySize[k], sizeof(int)); //Merge Sort needs a second array as large as the original one in the argument

			timer[i] = clock();
			merge_sort(tempArray, tempArrMerge, 0, arraySize[k] - 1);
			timer[i] = ((double)clock() - timer[i]) / CLOCKS_PER_SEC;
			printf("Run %d: %fs\n", i + 1, timer[i]);

			free(tempArrMerge);
		}
		//for i 21-27 use quick sort
		else if (i >= 21 && i <= 27) {
			timer[i] = clock();
			quick_sort(tempArray, 0, arraySize[k] - 1);
			timer[i] = ((double)clock() - timer[i]) / CLOCKS_PER_SEC;
			printf("Run %d: %fs\n", i + 1, timer[i]);
		}

		//if k == the Elements of arrPtrs (amount of arrays) - 1
		if (k == sizeof(arrPtrs) / sizeof(arrPtrs[0]) - 1) {
			k = 0;
		}
		else {
			k++;
		}
		free(tempArray);
	}

	//print out the timers
	printf("\t\t");
	for (i = 0; i < 7; i++) {
		printf("%d\t\t", arraySize[i]);
	}
	printf("\n");

	i = 0;

	printf("Insertion Sort:\t");
	while (i < 7) {
		printf("%fs\t", timer[i]);
		i++;
	}
	printf("\n");

	printf("Bubble Sort:\t");
	while (i < 14) {
		printf("%fs\t", timer[i]);
		i++;
	}
	printf("\n");

	printf("Merge Sort:\t");
	while (i < 21) {
		printf("%fs\t", timer[i]);
		i++;
	}
	printf("\n");

	printf("Quick Sort:\t");
	while (i < 28) {
		printf("%fs\t", timer[i]);
		i++;
	}
	printf("\n");


	wait_for_enter();

	for (i = 0; i < sizeof(arrPtrs) / sizeof(arrPtrs[0]); i++) {
		free(arrPtrs[i]);
	}

	return;
}
