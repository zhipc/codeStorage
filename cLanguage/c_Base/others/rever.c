#include <stdio.h>
#include <string.h>

int jiecheng(int n)
{
    if (n > 1) {
        return jiecheng(n - 1)*n;
    } else {
        return 1;
    }
}

void rever(char *arr)
{
    int i, j;
    char tmp;
    for (i = 0, j = strlen(arr) - 1; i < j; i++, j--) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main()
{
    char str[100] = {0};
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    rever(str);
    printf("%s\n", str);
    return 0;
}
