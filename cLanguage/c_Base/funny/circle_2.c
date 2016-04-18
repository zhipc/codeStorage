#include <stdio.h>
#define N 41     //一共有41个人
#define M 3      //数到3退出

int main()
{
    int arr[N] = {0};
    int count = 0;    //退出的人数
    int flag = 0;     //报数
    int i = 0;
    while (count < N) {
        if (arr[i] != -1) {
            arr[i] = ++flag;
        }
        if (arr[i] % M == 0) {
            //flag = 0;
            count++;
            arr[i] = -1;
            printf("%d\n", i + 1);
        }
        i++;
        i %= N;
        /*
        if (i == N) {
            i = 0;
        }
        */
    }
    return 0;
}
