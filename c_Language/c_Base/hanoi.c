#include <stdio.h>
void move(char c,int i,char d)
{
    static int count=1;
    printf("take %d to %c from %c\n",i,d,c);
    printf("move %d\n", count++);
}
void hanoi(int n,char x,char y,char z)
{
    if(n==1)
    {
        move(x,1,z);
    }
    if(n>1)
    {
        hanoi(n-1,x,z,y);
        move(x,n,z);
        hanoi(n-1,y,x,z);
    }
}
int main()
{
    int n=10;
    char x='x',y='y',z='z';
    hanoi(n,x,y,z);
    return 0;
}
