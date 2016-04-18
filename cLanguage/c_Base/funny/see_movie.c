#include <stdio.h>

int main()
{
    do {
        printf("gril, go to see movie?(y/n)\n");
    } while (getchar() != 'y' && getchar());
    printf("you pay for\n");
    return 0;
}
