/*
 *删除数组中相同的元素！(整形数组5)
 *      1 1 2 1 2 -> 1 2 0 0 0 
 *
 * */
#include <stdio.h>

void delete_arr(int arr[], int length)
{
    int i, j;
    int result = 0;
    arr[result++] = arr[0];
    for (i = 1; i < length; i++) {
        for (j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                break; 
            }
        }
        if (j == i) {
            arr[result++] = arr[i];
        }
    }
    for (i = result; i < length; i++) {
        arr[i] = 0;
    }
}

int main()
{
    int arr[] = {1,1,2,1,2};
    int i;
    delete_arr(arr, 5);
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
