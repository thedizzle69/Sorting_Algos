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

void cls() {
	//clear screen function using Regex

	printf("\x1b[H\x1b[2J\x1b[3J");
	//using ANSI escape Codes '\e', but in Hex format \x1b 
	//'[H' moves cursor into upper right pos
	//'[2J'  puts everything in the console into the scrollback buffer
	//'[3J' clears the scrollback buffer

}

int get_random_integer() { //make a random integer between -32768 and 32767 and returns this integer

	return (rand() << 15 | rand()) % 65536 - 32768;

}

int* generate_array(int arraySize) {

	int i;
	int* arr;

	arr = (int*)calloc(arraySize, sizeof(int)); //reserves memory for array

	if (arr) { //if calloc returns NULL, skip and return NULL
		for (i = 0; i < arraySize; i++) {

			arr[i] = get_random_integer(); //write a random integer in the elements of the array
		}

		return arr; //returns adress to the array that was created
	}
	return NULL; //returns NULL if calloc couldnt reserve memory
}

void print_array(int* arrPtr, int arraySize) {

	int i, j, k;
	int* tempPtr;

	i = 0;
	k = 0;

	printf("Array with %d Elements:\n", arraySize);

	if (arraySize / 15 != 0) { //if the array has more than 15 elements
		for (i = 0; i < arraySize / 15; i++) { //loop through the rows (without the last one, which has <10 elements)

			for (j = 0; j < 15; j++) { //loop through the 15 elements in each row
				tempPtr = arrPtr + k;
				printf("%d\t", *tempPtr); //print the value
				k++; //counter for the elements
			}

			printf("\n");
		}
	}
	if (arraySize % 15 != 0) { //if the array cant be completely printed with the first loop
		for (j = 0; j < arraySize % 15; j++) { //loop through the last elements
			tempPtr = arrPtr + j + k;
			printf("%d\t", *tempPtr);
		}
	}
	printf("\n\n");

	return;
}

int check_sort(int* arrPtr, int arraySize) {

	int i;

	for (i = 0; i < arraySize - 1; i++) {

		if (arrPtr[i] > arrPtr[i + 1]) { //if the next element of the array is bigger than the one before, the array is not sorted ascending
			return 0; //return 0 if the array is not sorted
		}
	}
	return 1; //return 1 if the array is sorted
}

void wait_for_enter() {

	char input_char[2];

	printf("Press Enter (sometimes need to be pressed twice) to continue!\n");
	fgets(input_char, 2, stdin);
	getchar();
	//I'm not happy about how that looks, but somehow fgets and getchar works together, to bypass Inputstream Buffer issues...
	//they dont work alone but apes together strong

	return;
}

float timer_avg(float timer[], int arraySize) {

	int i;
	float sum = 0, avg = 0;

	for (i = 0; i < arraySize; i++) {
		sum = sum + timer[i];
	}

	avg = sum / arraySize;

	return avg;
}

float timer_min(float timer[], int arraySize) {

	int i;
	float min;

	min = timer[0];

	for (i = 0; i < arraySize; i++) {

		if (min > timer[i]) {
			min = timer[i];
		}

	}
	return min;
}

float timer_max(float timer[], int arraySize) {

	int i;
	float max;

	max = timer[0];

	for (i = 0; i < arraySize; i++) {

		if (max < timer[i]) {
			max = timer[i];
		}

	}
	return max;
}