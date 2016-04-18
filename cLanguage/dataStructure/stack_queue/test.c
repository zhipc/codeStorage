#include <stdio.h>

int main()
{
    int arr[2][5] = {{5,8,2,3,4}, {5,6,7,8,9}};
    int **p = (int **)arr;
    printf("*p = %d\n", *p);
    printf("*(p+1) = %d\n", *(p+1));

    printf("*p+1 = %d\n", *p + 1);
    return 0;
}
