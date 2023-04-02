#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>


int main() {

    double x = 2;
    double y = 1;
    
    printf("Введите значение x: ");
    scanf("%d",&x);
    printf("Введите значение y: ");
    scanf("%d",&y);
    
    if ((x >= 0) && (y >= 0) && (x <= 5) && (y <= 5) && ((pow((y-5),2) + pow((x-5),2)) >= 25)){
        printf("1");
    } 
    else{
        printf("0");
    }
    return 0;
}

//Тесты:
// (-1,-1) (False)
// (-1,5) (False)
// (6,0) (False)
// (0,6) (False)
// (5,5) (False)

// (0,0) (True)
// (1,1) (True)
// (0,5) (True)
// (5,0) (True)
// (2,1) (True)