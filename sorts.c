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

void insertion_sort(int* arrPtr, int arraySize) {

	int i, key, j;
	for (i = 1; i < arraySize; i++) {

		key = arrPtr[i];
		j = i - 1;

		while (j >= 0 && arrPtr[j] > key) {
			arrPtr[j + 1] = arrPtr[j];
			j = j - 1;
		}
		arrPtr[j + 1] = key;
	}

	return;
}

void bubble_sort(int* arrPtr, int arraySize) {

	int i, j, temp;

	for (i = 1; i < arraySize; i++) { 

		for (j = 0; j < arraySize - 1; j++) {

			if (arrPtr[j] > arrPtr[j + 1]) {

				temp = arrPtr[j];
				arrPtr[j] = arrPtr[j + 1];
				arrPtr[j + 1] = temp;

			}
		}
	}
	return;
}

void merge_sort(int* arrPtr, int* tempArr, int arrayStart, int arrayEnd) {

		if (arrayEnd <= arrayStart) {
			return;     // the subsection is empty or a single element
		}

		int mid = (arrayStart + arrayEnd) / 2;

		// left sub-array is a[ArrayStart .. mid]
		// right sub-array is a[mid + 1 .. ArrayEnd]

		merge_sort(arrPtr, tempArr, arrayStart, mid);     // sort the left sub-array recursively
		merge_sort(arrPtr, tempArr, mid + 1, arrayEnd);     // sort the right sub-array recursively

		int pointer_left = arrayStart;       // pointer_left points to the beginning of the left sub-array
		int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
		int k;

		// we loop from arrayStart to arrayEnd to fill each element of the final merged array
		for (k = arrayStart; k <= arrayEnd; k++) {
			if (pointer_left == mid + 1) {      // left pointer has reached the limit
				tempArr[k] = arrPtr[pointer_right];
				pointer_right++;
			}
			else if (pointer_right == arrayEnd + 1) {        // right pointer has reached the limit
				tempArr[k] = arrPtr[pointer_left];
				pointer_left++;
			}
			else if (arrPtr[pointer_left] < arrPtr[pointer_right]) {        // pointer left points to smaller element
				tempArr[k] = arrPtr[pointer_left];
				pointer_left++;
			}
			else {        // pointer right points to smaller element
				tempArr[k] = arrPtr[pointer_right];
				pointer_right++;
			}
		}

		for (k = arrayStart; k <= arrayEnd; k++) {      // copy the elements from tempArr[] to arrPtr[]
			arrPtr[k] = tempArr[k];
		}
	}	

void quick_sort(int* arrPtr, int arrayBegin, int arraySize) {

	int i, j, pivot, temp;

	if (arrayBegin < arraySize) {
		pivot = arrayBegin;
		i = arrayBegin;
		j = arraySize;

		while (i < j) {
			while (arrPtr[i] <= arrPtr[pivot] && i < arraySize)
				i++;
			while (arrPtr[j] > arrPtr[pivot])
				j--;
			if (i < j) {
				temp = arrPtr[i];
				arrPtr[i] = arrPtr[j];
				arrPtr[j] = temp;
			}
		}

		temp = arrPtr[pivot];
		arrPtr[pivot] = arrPtr[j];
		arrPtr[j] = temp;
		quick_sort(arrPtr, arrayBegin, j - 1);
		quick_sort(arrPtr, j + 1, arraySize);

	}
	return;
}