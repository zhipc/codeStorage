#include <stdio.h>
#define TOTAL 41
#define SPLIT 3
#define REST 1

struct people {
    int id;
    int flag;
};

int main()
{
    int remain = TOTAL;
    int count = 1;

    struct people peo[TOTAL];
    int i = 0;
    for (i = 0; i < TOTAL; i++) {
        peo[i].id = i + 1;
        peo[i].flag = 1;
    }

    while (remain > REST) {
        if (peo[count].flag == 1) {
            if (count % SPLIT == 0) {
                peo[count].flag == 0;    
                printf("peo[%d] is removed!\n", count);
                remain--;
            }
            count = count++ % TOTAL;
        }
    }
    return 0;
}
