#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define ARRSIZE 10

void init_arr(int arr[], int length)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        arr[i] = rand()%100;
    }
}

void output_arr(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[ARRSIZE] = {0};
    init_arr(arr, ARRSIZE);
    sort(arr, ARRSIZE);
    output_arr(arr, ARRSIZE);
    return 0;
}
