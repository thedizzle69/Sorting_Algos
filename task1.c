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

void task1() {

	cls();
	printf("Task 1: Base Implementation:\n\n");

	int* arrPtrs[12];
	int arraySize[12] = { 8, 16, 64, 8, 16, 64, 8, 16, 64, 8, 16, 64 };

	unsigned int i = 0;

	printf("Insertion Sorting:\n\n");
	while (i < 3) {
		arrPtrs[i] = generate_array(arraySize[i]); //generate the array and fill it with random integers

		printf("Random:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the unsorted array (argument is the pointer to the array)

		insertion_sort(arrPtrs[i], arraySize[i]); //sorting the array

		if (!check_sort(arrPtrs[i], arraySize[i])) { //check if array is sorted
			printf("There was a problem with the sorting!\n");
			wait_for_enter();
			return;
		}

		printf("Sorted:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the sorted array

		i++;
	}

	wait_for_enter();
	cls();

	printf("Bubble Sorting:\n\n");
	while (i < 6) {
		arrPtrs[i] = generate_array(arraySize[i]); //generate the array and fill it with random integers

		printf("Random:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the unsorted array (argument is the pointer to the array)

		bubble_sort(arrPtrs[i], arraySize[i]); //sorting the array

		if (!check_sort(arrPtrs[i], arraySize[i])) { //check if array is sorted
			printf("There was a problem with the sorting!\n");
			wait_for_enter();
			return;
		}

		printf("Sorted:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the sorted array

		i++;
	}

	wait_for_enter();
	cls();

	printf("Merge Sorting:\n\n");
	while (i < 9) {
		arrPtrs[i] = generate_array(arraySize[i]); //generate the array and fill it with random integers

		int* tempArrMerge = (int*)calloc(arraySize[i], sizeof(int)); //Merge Sort needs a second array as large as the original one in the argument

		printf("Random:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the unsorted array (argument is the pointer to the array)

		merge_sort(arrPtrs[i],tempArrMerge, 0, arraySize[i] - 1); //sorting the array

		if (!check_sort(arrPtrs[i], arraySize[i])) { //check if array is sorted
			printf("There was a problem with the sorting!\n");
			wait_for_enter();
			return;
		}

		printf("Sorted:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the sorted array

		free(tempArrMerge);

		i++;
	}

	wait_for_enter();
	cls();

	printf("Quick Sorting:\n\n");
	while (i < 12) {
		arrPtrs[i] = generate_array(arraySize[i]); //generate the array and fill it with random integers

		printf("Random:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the unsorted array (argument is the pointer to the array)

		quick_sort(arrPtrs[i], 0, arraySize[i] - 1); //sorting the array (-1 is because the sort algo needs the last array element)

		if (!check_sort(arrPtrs[i], arraySize[i])) { //check if array is sorted
			printf("There was a problem with the sorting!\n");
			wait_for_enter();
			return;
		}

		printf("Sorted:\n");
		print_array(arrPtrs[i], arraySize[i]); //print the sorted array

		i++;
	}

	wait_for_enter();

	for (i = 0; i < sizeof(arrPtrs) / sizeof(arrPtrs[0]); i++) {
		free(arrPtrs[i]);
	}
	return;
}