#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "set.h"

/*
Andrew Nguyen
COEN 12 Project 2
FRIDAY LAB

Description:
This program uses sequential search to list elements in a data array of a set in an unsorted order
*/

//set includes count, length, and character pointer -> pointer data
struct set
{
	int count;
	int length;
	char** data;
};

//creates and initializes the SET
//returns poter to a new set with length maxElts
//O(1)
SET *createSet(int maxElts) 
{
	//create SET pointer and allocate memory
	SET *sp;
	sp = malloc(sizeof(SET));
	assert(sp != NULL);

	//initialize variables
	sp -> count = 0;
	sp -> length = maxElts;
	sp -> data = malloc(sizeof(char*) *maxElts);
	assert(sp -> data != NULL);
	return sp;
}

//frees the array and strings in memory
//O(n)
void destroySet(SET *sp)
{
	assert(sp != NULL);
	int i;

	//frees all indexes of data
	for(i = 0; i < sp -> count; i++)
	{	
		free(sp -> data[i]);
	}

	//free data array and set
	free(sp -> data);
	free(sp);
}

//returns the number of elements in an array 
//O(1)
int numElements(SET *sp)
{
	assert(sp != NULL);
	return sp -> count;
}

//sequential search that searches from index 0 to count for the element and returns the address
//O(n)
static int search(SET *sp, char *elt)
{
	int i;

	//searches from index o, to count for element
	for(i = 0; i < sp -> count; i++)
	{
		//if element and array address are equal at the index, return
		if(strcmp(sp -> data[i], elt) == 0)
		return i;
	}

	//if not found, return -1
	return -1;
}

//adds element to the set by allocating memory and copying the element into the data array
//O(n)
void addElement(SET *sp, char *elt)
{
	assert(sp != NULL && elt != NULL);

	//once count is equal to length, can no longer add
	if(sp -> count == sp -> length)
	return;

	//if the elemnt is not found, then insert then allocate space and insert the element 
	if(search(sp, elt) == -1)
	{
		sp -> data[sp -> count] = strdup(elt);
		sp -> count++;	
	}
}

//removes element in the set by freeing the element and taking it out of the data arary
//O(n)
void removeElement(SET *sp, char *elt)
{
	assert(sp != NULL && elt != NULL);

	//calls search function
	int x = search(sp, elt);

	//if the element is found, then free the space and delete element
	if(x == 0)
	{
		free(sp -> data[x]);
		sp -> data[x] = sp -> data[--sp -> count];
		sp -> count--;
	}
}

//finds element by searching for the element by the index in the data
//returns the address of the element.
//O(n)
char *findElement(SET *sp, char *elt)
{
	//calls the search function
	int index = search(sp, elt);

	//if not found, return NULL, else return the address of element
	if(index == -1)
	return NULL;
	return sp->data[index];
		
}

/*allocates a new spot for memory and copies the array into 
the new area and returns the copied array of elts*/
//O(n)
char **getElements(SET *sp)
{
	assert(sp != NULL);

	//initializes array and allocates space
	char **newloc = malloc(sizeof(char*)* sp->count);

	//copy the array into the new location, return the array
	newloc = sp -> data;
	return newloc;
}

//END
