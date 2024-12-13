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

void task4() {

	cls();
	printf("Task 4: Insertions Sort with Lists:\n\n");

	int* arrPtrs[1];
	int arraySize[1] = { 2048 };
	float timer[4]; // 2 timer for init comparison and 2 for sort performance

	int* tempArray;

	unsigned int i; //thats unsigned because of Wextra
	int j, k = 0; //running from 0 to the elements of arrPtrs (used for arrPtrs[k] and arraySize[k]

	//clear timer array
	for (i = 0; i < 4; i++) {
		timer[i] = 0;
	}

	//generate the 1 random arrays that will get sorted
	for (i = 0; i < sizeof(arrPtrs) / sizeof(arrPtrs[0]); i++) {
		timer[0] = clock(); //timer 0 init performance of random array
		arrPtrs[i] = generate_array(arraySize[i]);
		timer[0] = ((double)clock() - timer[0]) / CLOCKS_PER_SEC;
	}

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

    //print the array
    printf("Random:\n");
    print_array(tempArray, arraySize[k]);


	timer[1] = clock(); //timer 1 sorting performance of array
	insertion_sort(tempArray, arraySize[k]);
	timer[1] = ((double)clock() - timer[1]) / CLOCKS_PER_SEC;
	printf("Insertion Sorting with Array:\n");

	//print the array
	printf("Sorted:\n");
	print_array(tempArray, arraySize[k]);

	printf("Init: %fs\t Sorting performance: %fs\n\n", timer[0], timer[1]);

	//if k == the Elements of arrPtrs (amount of arrays) - 1
	if (k == sizeof(arrPtrs) / sizeof(arrPtrs[0]) - 1) {
		k = 0;
	}
	else {
		k++;
	}



	node root = init_list();

	timer[2] = clock();
	if (copy_array_to_list(root, arrPtrs[0], arraySize[0]) == 0) {
		printf("Error: Couldnt reserve Memory!\n");
		wait_for_enter();
		return;
	}
	timer[2] = ((double)clock() - timer[2]) / CLOCKS_PER_SEC;



	timer[3] = clock();
	insertion_sort_list(root);
	timer[3] = ((double)clock() - timer[3]) / CLOCKS_PER_SEC;

	printf("Insertion Sorting with List:\n");
	printf("Init: %fs\t Sorting performance: %fs\n\n", timer[2], timer[3]);

	wait_for_enter();

	free_list(root);

	free(tempArray);

	for (i = 0; i < sizeof(arrPtrs) / sizeof(arrPtrs[0]); i++) {
		free(arrPtrs[i]);
	}

	return;
}