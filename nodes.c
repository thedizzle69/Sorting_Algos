#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "standardFunctions.h"
#include "sorts.h"
#include "nodes.h"

node init_list() {

	// reserve memory
	node root = (node)malloc(sizeof * root);
	// malloc error check
	if (root == NULL) {
		return NULL;
	}

	// write into node
	root->next = NULL;
	root->data = 0;

	// return pointer to node
	return root;
}

void delete_nextNode(node list) {
	node temp = list->next;
	list->next = list->next->next;
	free(temp);
	return;
}

void free_list(node list) {

	node temp;
	node next;

	//set current element to root
	temp = list;

	//run through list
	while (temp != NULL) {
		next = temp->next;
		free(temp);
		temp = next;
	}
}

int copy_array_to_list(node list, int* arr, int arraySize) {

	int i;
	node tempNodeLoop = 0;

	for (i = 1; i < arraySize - 1; i++) {

		node tempNode = (node)malloc(sizeof(struct list));
		if (tempNode == NULL) {
			return 0;
		}

		if (i == 1) { //first loop to set root
			list->data = arr[i - 1]; //write arr[0] to root (for begins at 1!!!)
			list->next = tempNode; //set pointer to new element
			tempNode->data = arr[i]; //write arr[1] to second element
			tempNodeLoop = tempNode; //copy new element for loop
		}
		else {
			tempNodeLoop->next = tempNode; //set pointer from element of the loop before to the new element
			tempNode->data = arr[i]; //put the data into the new element
			tempNode->next = NULL; //set next pointer to null
			tempNodeLoop = tempNode; //copy new element for loop
		}
	}
	return 1;
}

void print_list(node list) {

	while (list != NULL) { // print everything beginning from the node in the argument until the last element closes the loop
		printf("%d\n", list->data);
		list = list->next;
	}
	return;
}

node insertion_sort_list(node list) {

	node temp = list;
	node tempNext = 0;
	node newRoot = list;
	int i = 0;

	while (temp->next != NULL) {
		if (temp->data > temp->next->data) {
			if (temp == newRoot) { //if the newest root is beeing moved forward set a new root element
				newRoot = temp->next; //temp->next is getting the new root
			}
			tempNext = temp->next;
			temp->next = temp->next->next;
			tempNext->next = temp;

			node iNode = newRoot;
			while (i > 0) {
				i--;
				if (i == 0) { iNode->next = tempNext; }
				iNode = iNode->next;
			}
			i = 0;
			temp = newRoot; //set loop temp element to the first element
		}
		else {
			temp = temp->next;
			i++;
		}
		//printf("\n\n\n");
		//print_list(newRoot);
	}
	return newRoot;

}