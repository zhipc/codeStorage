#include <stdio.h>

int main()
{
    int x = 22;
    int y = 66;
    x = x + y;
    y = x - y;
    x = x - y;
    printf("%d\n%d\n", x, y);
	//一个数异或另一个数两次，其值不变
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("%d\n%d\n", x, y);
    return 0;
}
