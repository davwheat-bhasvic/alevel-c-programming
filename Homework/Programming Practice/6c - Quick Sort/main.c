#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define RANDOM_MAX_VALUE 10000000
#define COUNT 257000

void quicksort(int number[COUNT],int first,int last){
    int i, j, pivot, temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                ++i;
            while(number[j]>number[pivot])
                --j;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }

        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);

    }
}

int main(){
    int i, number[COUNT];
    clock_t timer;

    srand(time(NULL));
    printf("Generating data set: ");

    for(i=0;i<COUNT;i++){
       number[i]=rand()%RANDOM_MAX_VALUE;
//        printf(" %d",number[i]);
    }
    printf("\n \n");
    timer=clock(); //gets clock time before start

    quicksort(number,0,COUNT-1);

    printf("Sorted elements: ");
    for(i=0;i<COUNT;i++){
        printf(" %d",number[i]);}

    timer=clock()-timer; //takes start time from end time when sort finishes
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    printf("\n Time taken: %f", time_taken);
    return 0;
}