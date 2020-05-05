//
//  printArray.c
//  Project_P.A
//
//  Created by Anton on 5/5/20.
//  Copyright © 2020 Anton. All rights reserved.
//

#include "printArray.h"

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}
