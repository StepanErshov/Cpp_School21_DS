#include <stdio.h>

void print();

int main(int argc, char* argv[]){
    int a = 5;
    int Arr[4] = {1, 2, 3, 4};

    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 7;
    int* ptr1 = (int*)malloc(4 * sizeof(int));
    ptr1[0] = 8;
    ptr1[1] = 8;
    ptr1[2] = 8;
    ptr1[3] = 8;
    
    print();

    return 0;
}

void print(){
    int num = 8;
}

