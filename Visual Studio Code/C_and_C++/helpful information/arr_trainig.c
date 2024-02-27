#define ARR_SIZE 20
#include <stdio.h>
#include <stdlib.h>

void printArr(int*);

int main(){
    int i;
    int* ptrArr;
    // int arr[] = {20, 31, 45, 66, 8};
    ptrArr = (int*)malloc(ARR_SIZE * sizeof(int));
    for(i = 0; i < ARR_SIZE ; i++ ){
        ptrArr[i] = i + 15;
    }
    printArr(ptrArr);
    return 0;
}

void printArr(int* ptrArr){
    int i;
for(i = 0; i < ARR_SIZE; i++){
    printf("ptrArr[%d] = %d\n", i, ptrArr[i]);
    }
}

