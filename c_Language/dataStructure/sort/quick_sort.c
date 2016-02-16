/*
 *此快速排序实现为CPL中p74中的算法
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//第一种实现
void quick_sort(int arr[], int left, int right)
{
    int i, last;
    if (left >= right) {
        return;
    }
    swap(arr, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (arr[i] < arr[left]) {
            swap(arr, ++last, i);
        }
    }
    swap(arr, left, last);
    quick_sort(arr, left, last - 1);
    quick_sort(arr, last + 1, right);
}

//第二种实现
void quick_sort(int arr[], int start, int end)
{
	if (start < end) {		//递归调用也会判断条件是否成立
		//swap(arr[start], arr[(start + end)/2]);		//将中间的数字作为基准
		int base = arr[start];
		int i = start;
		int j = end;
		while (i < j) {		
			while (i < j && arr[j] >= base) {		//从右向左找第一个小于base的数
				j--;
			}
			if (i < j) {
				arr[i] = arr[j];
				i++;
			}
			while (i < j && arr[i] < base) {		//从左向右找第一个大于base的数
				i++;
			}
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}
		}
		arr[i] = base;
		quick_sort(arr, start, i - 1);
		quick_sort(arr, i + 1, end);
	}
}

int main()
{
    int arr[ARRSIZE] = {0};
    init_arr(arr, ARRSIZE);
    quick_sort(arr, 0, ARRSIZE - 1);
    output_arr(arr, ARRSIZE);
    return 0;
}
