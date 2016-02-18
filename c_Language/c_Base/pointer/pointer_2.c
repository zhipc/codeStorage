#include <stdio.h>

int main()
{
    int arr[5]={1,2,3,4,5};
    int *p=&arr[1];
    //printf("%d\n",p[2]);  //4  
    //printf("%d\n",arr[2]);   //3 
    int y=(*--p)++;//2        1
    printf("%d\n",y);//2      1 
    printf("%d\n",*p);//2 1   2 1
    printf("%d\n",arr[0]);//
    printf("%d\n",arr[1]);
    return 0;
}
