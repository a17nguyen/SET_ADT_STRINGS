SET_ADT_STRINGS PROJECT

Project By: Andrew Nguyen
Date: 10/08/2017

This file implements a set ADT for strings. The implementation files are the 
sorted.c and unsorted.c files.

unsorted.c: implements a set using an unsorted array of length m > 0, 
in which the first n ≤ m slots are used to hold n strings in some arbitrary order. 
It uses sequential search to locate an element in the array.  

sorted.c: implements a set using a sorted array of length m > 0, in which the first
n ≤ m slots are used to hold n strings in ascending order. It uses binary search to v
locate an element in the array.

For both implementations, rather than duplicating the search logic in several functions,
there is write an auxiliary function search that returns the location of an element in an array. 
It declares search as static so it is not visible outside of the source file.  
Search is used to implement the functions in the interface. The implementation allocates 
memory and copies the string when adding, and therefore also deallocates memory when removing.
