#include <stdio.h>

void ponters(int*, int, const int*);

int maint(int argc, char* argv[]){
    int *ptr;
    int *ptr1;
    int a = 15;
    int b = 20;

    ptr = &a;
    ptr1 = &b;

    printf("%d\n", a);
    printf("%d\n\n", *ptr);

    printf("%p\n", ptr);
    printf("%p\n", &a);
    printf("%p\n", &ptr);

    ponters(ptr, a, ptr1);
    printf("In main:\n");
    printf("%d\n", a);

    return 0;
}

void ponters(int* ptrFct, int value, const int* ptrConst){
    printf("pointerFcts:\n");
    printf("%d\n", *ptrFct);
    printf("%d\n", value);
    printf("%d\n", *ptrConst);

    value = 200;
    *ptrFct = 200;
    printf("%d\n", *ptrFct);

}