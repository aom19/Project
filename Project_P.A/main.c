//
//  main.c
//  Project_P.A
//
//  Created by Anton on 5/5/20.
//  Copyright © 2020 Anton. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "BubleSort.h"
#include "printArray.h"

struct tool
{
    int leftPoint;
    int radiusWork;
};

//Surface with grass
int areaTotal (int x , int y){
    return x*y;
}



int main() {
    
    struct tool t[20]; //array of tools
    int toolWidth[20]; // width of individual tool
    int areaWorkTool[20];  // array of individual work area of all tools;
    int length , width , numOfTools , i , surfaceWatered = 0;
    int totalArea = 0;
    float toolsNeeded  = 0;
    
//Read data
    
    printf("Give num of tools \n");
    scanf("%d",&numOfTools);
    

    printf("Give length  and width \n");
    scanf("%d",&length);
    scanf("%d",&width);

    for(i = 0 ; i< numOfTools ; i++){
        printf("\nEnter details of tool %d", i+1);
        
        printf("\nEnter the left point - ");
        scanf("%d",&t[i].leftPoint);
        
        printf("Enter the radius work - ");
        scanf("%d",&t[i].radiusWork);
    }
    
//Surface that work one tool
    //1. Width
        for(i = 0 ; i < numOfTools ; i++){
            //'cause can't calculate the last one with the same formula , t[i+1] will be undefined
            if( i  == numOfTools - 1  ){
                toolWidth[numOfTools - 1] = length - t[numOfTools - 1].leftPoint;
            }else{
                toolWidth[i] = t[i+1].leftPoint - t[i].leftPoint;
            }
        }
        //     check if calculate correct
        //    for(i = 0 ; i < numOfTools ; i++){
        //        printf("Radius work of tool[%d] - %d\n",i,toolWidth[i]);
        //    }
    
    //2. Area
        for(i = 0 ; i < numOfTools; i ++){
            //calculate the full radius zone;
            t[i].radiusWork *=2;
            //it's like a rectangle
            areaWorkTool[i] = toolWidth[i] * t[i].radiusWork;
        }
    
//Total zone watered
    
        for (i = 0; i< numOfTools; i++) {
            surfaceWatered += areaWorkTool[i];
        }
    
// Check the difference between areas;
    
    totalArea = areaTotal(width,length);
    
    if(totalArea - surfaceWatered == 0){
        printf("\nSuccess");
    }else if (totalArea - surfaceWatered !=0){
        printf("\nYou need more");
        int areaMissed = totalArea - surfaceWatered;
        
        //Sort array to know how many tools is needed;
        BubbleSort(areaWorkTool,numOfTools );
        for(i = 0 ; i < numOfTools ; i++){
            if(areaMissed <= areaWorkTool[i]){
                 toolsNeeded = 1;
                printf("It's enough 1");
            }else if(areaMissed > areaWorkTool[i]){
                
                toolsNeeded = trunc(totalArea / surfaceWatered) + 1; ;
            }
        }
        printf("\nTools needed : %g\n",toolsNeeded);
    }
    
    

        
    
    
    
    
    


    
    
    
    
    
    
    
    
    return 0;
}
