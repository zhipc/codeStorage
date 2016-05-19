#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRSIZE 10
#define RANGE_MIN 50
#define RANGE_MAX 200

void init_arr(int arr[], int length)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        arr[i] = RANGE_MIN + rand() % (RANGE_MAX - RANGE_MIN);
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

//根据标准计数排序思想编写
void countSort_standard(int arr[], int length)
{
    int range[RANGE_MAX - RANGE_MIN + 1] = {0};
    //可以使用int *tmp = calloc(length, sizeof(int));  使用calloc不要忘了free
    int tmp[ARRSIZE] = {0};
    int i;
    for (i = 0; i < length; i++) {
        range[arr[i] - RANGE_MIN]++;
    }   
    for (i = 1; i < RANGE_MAX - RANGE_MIN + 1; i++) {
        range[i] = range[i - 1] + range[i];
#ifdef DEBUG
        if (range[i - 1] != range[i]) {
            printf("range[%d] = %d\n", i, range[i]);
        }   
#endif
    }   
    //逆序输出确保稳定---->相同元素相对顺序不变
    for (i = length - 1; i >= 0; i--) {
        tmp[range[arr[i] - RANGE_MIN] - 1] = arr[i];
        range[arr[i] - RANGE_MIN]--;
    }   
    for (i = 0; i < length; i++) {
        arr[i] = tmp[i];
    }   
}

void countSort_my(int arr[], int length)
{
    int range[RANGE_MAX - RANGE_MIN + 1] = {0}; 

    int i, j, index = 0;
    for (i = 0; i < length; i++) {
        range[arr[i] - RANGE_MIN]++;
#ifdef DEBUG
        printf("range[%d] = %d\n", arr[i] - RANGE_MIN, range[arr[i] - RANGE_MIN]);
#endif
    }
    for (i = 0; i < RANGE_MAX - RANGE_MIN + 1; i++) {
        if (range[i] == 0) {
            continue; 
        }
#ifdef DEBUG
        printf("[%d] : %d\n", i + RANGE_MIN, range[i]);
#endif
        for (j = 0; j < range[i]; j++) {
            arr[index++] = i + RANGE_MIN;
        }
    }
}

int main()
{
    int arr[ARRSIZE] = {0};
    init_arr(arr, ARRSIZE);
    printf("before sort:\n");
    output_arr(arr, ARRSIZE);
    countSort(arr, ARRSIZE);
    printf("after sort:\n");
    output_arr(arr, ARRSIZE);
    return 0;
}
