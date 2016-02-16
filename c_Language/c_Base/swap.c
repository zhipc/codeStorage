#include <stdio.h>

int main()
{
    int x = 22;
    int y = 66;
    x = x + y;
    y = x - y;
    x = x - y;
    printf("%d\n%d\n", x, y);
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("%d\n%d\n", x, y);
    return 0;
}
