#include <stdio.h>

int main()
{
    int x;//0-9;
    do{
        scanf("%d",&x);//%c   4353
        //printf("input err please input again\n");
    }while((x<0||x>9)&&printf("input err input again\n"));
    printf("%d\n",x);
    return 0;
}
