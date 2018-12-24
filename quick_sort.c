/*
 *  Quitck sort try.
 *
 *  Tags: Sorting, Quick Sort, Recursion
 *  Date: 10/14/2018 08:45 PM
 */ 

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void
print(int a[], int len)
{
    for (int i=0;i<len;i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
}

int
partition_hoares(int a[], int l, int r)
{
    int tmp;
    int i = l;
    int j = r;
    int p_val = a[r];
   
    while(1) {
        while((a[i] < p_val) && (i < j)) {
            i++;
        }

        while((a[j] >= p_val) && (i < j)) {
            j--;
        }
        if (i<j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        } else {
            break;
        }
    }
    tmp = a[j];
    a[j] = a[r];
    a[r] = tmp;
    return j;
/* 34,1,22,12,4,13,18*/
/* 13,1,22,12,4,34,18*/
/* 13,1,4,12,22,34,18*/
/* 13,1,4,12,18,34,22*/
}

int
partition(int a[], int l, int r)
{
    int tmp;
    int i;
    int part;
    int p_val = a[r];

    part = i = l;
    while(i<r){
        if (a[i] <= p_val) {
            if (i != part) {
                tmp = a[i];
                a[i] = a[part];
                a[part] = tmp;
            }
            part++;
        } 
        i++;
    }
    tmp = a[part];
    a[part] = a[r];
    a[r] = tmp;
    return part;
}

void
quick_sort(int a[], int l, int r)
{
    int pivot = 0;
    if (l >= r) {
        return;
    }
    pivot = partition(a,l,r);
    //pivot = partition_hoares(a,l,r);
    
    quick_sort(a,l,pivot-1);
    quick_sort(a,pivot,r);
}


int
main ()
{
    int i = 0;
    int a[10];
    srand(time(NULL));
    for(i=0;i<(sizeof(a)/sizeof(int));i++) {
        a[i] = rand()%100;
    }
    
    quick_sort(a, 0,(sizeof(a)/sizeof(int))-1);
    print(a,sizeof(a)/sizeof(int));
}

#if 0
    10,12,4,100,33,1,  13

    i=1, part=1
#endif
