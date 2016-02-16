void swap(int *x, int *y) 
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubble_sort(int arr[], int length)    //冒泡排序
{
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void select_sort(int arr[], int length)    //选择排序
{
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[j] < arr[i]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void radix_sort(int arr[], int length);      //基数排序

void quick_sort(int arr[], int length);     //快速排序

void sort(int arr[], int length)
{
    select_sort(arr, length);
}
