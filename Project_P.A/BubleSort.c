//
//  BubleSort.c
//  Project_P.A
//
//  Created by Anton on 5/5/20.
//  Copyright © 2020 Anton. All rights reserved.
//

#include "BubleSort.h"
//change values with places;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//the sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order."https://www.geeksforgeeks.org/c-program-for-bubble-sort/?ref=rp"
void BubbleSort(int arr[], int n)
{
    
   int i, j;
   for (i = 0; i < n-1; i++)
  
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
