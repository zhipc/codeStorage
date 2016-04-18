#include <stdio.h>
#include <string.h>

void op(char *str)
{
    char c;
    c = getchar();
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != c) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int main()
{
    char buf[100] = {0};
    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf) - 1] = '\0';
    op(buf);
    printf("%s\n", buf);
    return 0;
}
