#include <stdio.h>
#define TOTAL 41
#define SPLIT 3
#define REST 0

struct people {
    int id;
    int flag;
};

int main()
{
    int remain = TOTAL;
    int count = 0;

    struct people peo[TOTAL];
    int i = 0;
    for (i = 0; i < TOTAL; i++) {
        peo[i].id = i + 1;
        peo[i].flag = 1;
    }

    for (i = 0; remain > REST; i++) {
        i = i % TOTAL;
        if (peo[i].flag == 1) {
            count++;
            if (count % SPLIT == 0) {
                peo[i].flag = 0;    
                printf("peo[%d] is removed!\n", i + 1);
                remain--;
            }
        }
    }
    return 0;
}
