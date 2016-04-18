#include <stdio.h>
#define N 41
#define M 2


int main()
{
    int arr[N];
    int x=0;//记录数到几
    int y=0;//记录数到那个学士
    int count=0;//记录多少个学生退出
    for(x=0;x<N;x++)
        arr[x]=x+1;
    x=0;
    //while(count!=N)
    while(count!=(N-M)) {
        if(arr[y]!=0)
            x++;
        if(x==3) {
            printf("%d\n", arr[y]);
            arr[y]=0;
            x=0;
            count++;
        }
        y++;
        y=y%N;
    }
    printf("*****************************\n");
    for(x=0;x<N;x++) {
        if(arr[x]!=0)
            printf("%d\n",arr[x]);
    }
    return 0;
}
