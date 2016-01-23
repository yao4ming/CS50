/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

//#define LIMIT 65536 

int binarySearch(int value, int values[], int start, int end) {
    
    //base case
    if(start > end) {
        //printf("Not Found\n");
        return 0;
    }
    
    //get midpoint
    int mid = (start + end) / 2;
    
    //compare value with midpoint
    if (value > values[mid]) {
        return binarySearch(value, values, mid + 1, end);
    }
    else if (value < values[mid]) {
        return binarySearch(value, values, start, mid - 1);
    }
    else {
        //printf("Found\n");
        return 1;    //value == midpoint
    }
}

bool search(int value, int array[], int n) {
    
    int found = binarySearch(value, array, 0, n - 1);
    if (found) {
        return true;
    }
    else {
        return false;
    }
}

void countingSort(int values[], int n) {
    
    //counting sort O(n)
    int len = 65536 + 1;
    int count[len];
    int sorted[n];
    
    //init count array to 0
    for (int i = 0; i < len; i++) count[i] = 0;
    
    //------------------------STEP 1------------------------------
    //foreach value in values add 1 to value of corresponding array index
    for (int i = 0; i < n; i++) {
        int index = values[i];
        count[index]++;
    }
    //-----------------------STEP 2--------------------------------
    //add the value of an element(i) to it's following element(i+1)
    for (int i = 0; i < len; i++) {
        count[i+1] += count[i];
    }
    
    //-----------------------STEP 3--------------------------------
    //correspond unsorted array value with count array index
    //subtract 1 from count array value
    //correspond output array index with counting value
    //correspond output array value with counting index
    for (int i = 0; i < n; i++) {
        sorted[--count[values[i]]] = values[i];
        //printf("%i - index %i - value \n", count[values[i]], values[i]);
    }
    
    for (int i = 0; i < n; i++) values[i] = sorted[i];
    return;
}

void sort(int values[], int n) {
    
    countingSort(values, n);
}

