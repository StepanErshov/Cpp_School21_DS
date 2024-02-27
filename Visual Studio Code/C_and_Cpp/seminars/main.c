#include "add.h"
#include <stdio.h>

extern int var;

int main(){
    printf("%d", var);

    DoWork();
    
    return 0;
}