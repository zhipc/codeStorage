/*
     合并2个有序数组(5)到第三个数组(10)中
     函数-合并int *arr
     1 3 5 
     1 5 7--->1 1 3 5 5 7 
 *
 * */
#include <stdio.h>
#define N 5
void input_arr(int arr[]);
void comb_arr(int *arr1,int *arr2,int *arr3);
void output_arr(int arr[]);
int main()
{
    int arr1[N],arr2[N],arr3[N*2];
    input_arr(arr1);
    input_arr(arr2);
    comb_arr(arr1,arr2,arr3);
    output_arr(arr3);
    return 0;
}
void input_arr(int arr[])
{
    int *p=arr;
    while(p<arr+N) {
        scanf("%d",p++);       
    }
}
void comb_arr(int *arr1,int *arr2,int *arr3)
{
    int *p1,*p2,*p3;
    for(p1=arr1,p2=arr2,p3=arr3; (p1<arr1+N)&&(p2<arr2+N); ) {
        if(*p1<*p2) {
            *p3++=*p1++;
        } else {
            *p3++=*p2++;
        }
    }
    while(p1<arr1+N) {
        *p3++=*p1++;
    }
    while(p2<arr2+N) {
        *p3++=*p2++;
    }
}
void output_arr(int arr[])
{
    int *p=arr;
    while(p<arr+2*N) {
        printf("%d  ",*p++); 
    }
    putchar('\n');
}

