/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //ensure proper usage
    if(value < 0)
        return false;
        
    //look for needle in haystack
    for(int i = 0; i < n; i++)
    {
        if(value == values[i])
            return true;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0; i < n - 1; i++)  //loop through unsorted values
    {
        for(int j = i + 1; j < n; j++)  
        {
            if(values[i] > values[j])   //find min value
                swap(&values[i], &values[j]); //sort min value
        }
    
    }
    return;
}
