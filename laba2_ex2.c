#include <stdio.h>
#include <stdlib.h>     
#include <time.h>       

#define ROWS 10          
#define COLS 10

int RandArr();

int arr[ROWS][COLS];    
int i, j, x;

int main()
{
    RandArr();

    
    printf("Введите число: ");
    scanf("%d", &x);

   
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (arr[i][j] == x)
            {
                printf("Число %d находится в строке %d, столбце %d\n", x, i + 1, j + 1);
                return 0;   
            }
        }
    }

    printf("Число %d не найдено в массиве\n", x);

    return 0;
}

int RandArr(){

        srand(time(NULL));      
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 100;  
            printf("%5d ", arr[i][j]); 
        }
        printf("\n");   
    }
return 0;
}