#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

int main(){
    int b = 30;
    int a = 15;
    int arr[2] = {1, 2};
    void* ptr = &a;
    void *ptr2 = &arr;
    void *ptr3;
    printf("%d\n", *((int*)ptr));

    ptr3 = malloc(sizeof(int));
    free(ptr3);

    swap(&a, &b, sizeof(char));
    printf("%d\t", a);
    printf("%d\n", b);
    return 0;
}

void swap(void* a, void* b, size_t size){
    char* tmp;
    tmp = (char*)malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);

}