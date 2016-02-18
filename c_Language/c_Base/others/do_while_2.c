#include <stdio.h>

int main()
{
    srand(time(NULL));
    int x = rand()%10 + 1;
    int input = 0;
    printf("please guess:\n");
    do {
        scanf("%d", &input);
        if (input > x) {
            printf("too big\n");
        } else if (input < x) {
            printf("too small\n");
        } else {
            printf("right\n");
            break;
        }
    } while ((input <= 10 && input >= 1) || printf("please input 1~10\n"));
    return 0;
}
