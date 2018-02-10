/*
Andrew Nguyen
Project 2
Friday Lab
Description:
Program uses binary search to list elements in a data array of a set in alphabetical order
*/


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "set.h"

//set includes count, length, and character pointer -> pointer data
struct set
{
	int count;
	int length;
	char** data;
};

//returns a pointer to a new set with length maxElts
//O(1)
SET *createSet(int maxElts) 
{
	//create SET pointer and allocate memory
	SET *sp;
	sp = malloc(sizeof(SET));
	assert(sp != NULL);
	
	//initializes variables
	sp -> count = 0;
	sp -> length = maxElts;
	sp -> data = malloc(sizeof(char*) *maxElts);
	assert(sp -> data != NULL);
	return sp;
}

//frees the array and strings in memory pointed by sp
//O(n)
void destroySet(SET *sp)
{
	assert(sp != NULL);
	int i;

	//initializes the variables
	for(i = 0; i < sp -> count; i++)
		free(sp -> data[i]);
	free(sp -> data);
	free(sp);
}

//returns the number of elements in the set
//O(1)
int numElements(SET *sp)
{
	assert(sp != NULL);
	return sp -> count;
}

//binary search method to locate an existing element
//O(logn)
static int search(SET *sp, char *elt, bool *found)
{
	assert(sp != NULL && elt != NULL);
	int lo, hi, mid, diff;

	//first value in array
	lo = 0;	
	
	//last value i array
	hi = sp -> count -1;

	//runs loop until lo equals high
	while(lo <= hi) 
	{
		mid = (lo + hi) / 2;

		//compares the strings to determine if value is in the first or second half of array
		diff = strcmp(elt, sp -> data[mid]);

		//if value is in first half
		if(diff < 0)
		{
			hi = mid - 1;
		}

		//if value is in second half
		else if(diff > 0)
		{
			lo = mid +1;
		}
		
		//value found
		else 
		{
			*found = true;
			return mid;
		}
	}

	//value not found
	*found = false;
	return lo;
}

//searches then adds non-existing element to the set
//O(logn)
void addElement(SET *sp, char *elt)
{
	assert(sp != NULL && elt != NULL && sp->count < sp->length);
	bool found = true;
	int i;

	//calls search function to see if element is found
	int idx = search(sp, elt, &found);

	//cannot add element if count = length
	if(sp -> count == sp -> length)
	return;

	//if not found, adds to the index it belongs in and shifts existing elements down
	if(!found)
	{
		for(i = sp -> count; i > idx; i--)
		{
			sp -> data[i] = sp -> data[i-1];
		}
		sp -> data[idx] = strdup(elt);
		sp -> count++;
	}
}	



//removes element in the set by freeing the element and taking it out of the data arary
//O(logn)
void removeElement(SET *sp, char *elt)
{
	assert(sp != NULL && elt != NULL);
	bool found = true;
	int i;

	//calls search function to see if element is found
	int x = search(sp, elt, &found);

	//if found, the delete from array and shift everything up
	if(found)
	{
		free(sp -> data[x]);
		for(i = x + 1; i < sp -> count; i++)
		{
			sp -> data[i - 1] = sp -> data[i];
		}
		sp -> count--;
	}
}

//finds element by searching for the element by the index in the data
//returns the address of the element
//O(logn)
char *findElement(SET *sp, char *elt)
{
	assert(sp != NULL && elt != NULL);
	bool found = true;
	int index = search(sp, elt, &found);
	if(index != found)
	{	
		return NULL;
	}
	return sp->data[index];
		
}

/*allocates a new spot for memory and copies the 
array into new area and returns the copies array of elts*/
//O(n)
char **getElements(SET *sp)
{	
	assert(sp != NULL);

	//initializes array and allocates memory for that array
	char **newloc = malloc(sizeof(char*)* sp->count);

	//copies each element of data into the new array
	newloc = sp -> data;
	return newloc;
}

