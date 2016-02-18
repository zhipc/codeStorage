/*
 *此例中注意指针pi
 *
 * */
#include <stdio.h>

int main()
{
    int arr[2][3]={{34,54,65},{675,76,71}};
    printf("%p\n",arr+2);//二级地址 24
    printf("%p\n",*arr+1);//一级地址 4
    printf("%d\n",*(*arr+1));//取值 54
    printf("%d\n",*(*(arr+1)+2));//取值 71
    int **pi=(int **)arr;
    printf("%d\n",*(pi+1)+2);//???
    printf("%d\n",*(*(pi+1)+2));//???
    return 0;
}
