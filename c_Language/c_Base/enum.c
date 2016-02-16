#include <stdio.h>

enum Time{
    DAY=3,
    NIGHT=3,
    MAY=31,
    JUL=31
};

enum State{
    OK,
    FAILED
};

enum Operation{
    OPEN=1,
    SAVE,
    DEL,
    UPATE,
    QUERY,
};//switch()

int say(int age)
{
    if(age>18)
    {
        return OK;
    }else{
        return FAILED;
    }
}

enum esc{
    BELL='\a',
    BACK='\b',
    TAB='\t',
    RETURN='\r',
    NEWLINE='\n'
};


int main()
{
    enum Time t1=DAY;
    enum Time t2=NIGHT;
    
    printf("%d\n",t1);
    printf("%d\n",t2);
    return 0;
}
