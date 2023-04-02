#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* GetInput();
bool Testinput(char*);
int strToInt(char*);
void printInt(int);

int num;
char* a;
char* c;
int d;

int main(){
char* c = GetInput();
    if (Testinput(c) == true) {
        int d = strToInt(c);
        printInt(d);
        } 
    else {
    printf("Невозможно преобразовать к целому числу.\n");
        }
    return 0;
}

char* GetInput(){
    char* a = malloc(sizeof(char) * 256);
    printf("Введите что хотите:\n");
    scanf("%s", a);                            //Взависимости от того, как мы будем расспозновать переменную а
    return a;                                   //будет отличаться 
}

bool Testinput(char* a){
    int num;
    if (sscanf(a, "%d", &num) == 1) {
        return true;
        }       
    else {
    return false;
    }   
};
    
int strToInt(char* a){
    return atoi(a);
};

void printInt(int a){
    printf("%d\n", a);
}