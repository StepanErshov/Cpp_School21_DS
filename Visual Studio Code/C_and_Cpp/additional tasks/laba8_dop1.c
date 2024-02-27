#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define t 3
#define h 3

int matrix();

int main(){
    matrix();
    return 0;
}
int matrix(){
    int dep[t][h];
    int dep1[t][h];
    int sum = 0;
    int res[t][h];

     srand(time(NULL));
     FILE *hw8_dop1;
     FILE *hw8_dop2;
     hw8_dop1 = fopen("hw8_dop1.txt", "wt");
     hw8_dop2 = fopen("hw8_dop2.txt", "wt");
     for(int i = 0; i < t; i++)
     {
        for(int j = 0; j < h; j++)
        {
            dep[i][j] = rand() % 100;
            dep1[i][j] = rand() % 100;
            fprintf(hw8_dop1, " %d ", dep[i][j]);
            fprintf(hw8_dop2, " %d ", dep1[i][j]);
        }
        fprintf(hw8_dop1 ,"\n");
        fprintf(hw8_dop2 ,"\n");}

        fclose(hw8_dop1);
        fclose(hw8_dop2);

    for(int i = 0; i < t; i++){
        for(int j = 0; j < h; j++){
            for(int k = 0; k < t; k++){
                sum += dep[i][k] * dep1[k][j];
            }
        res[i][j] = sum;}
    }

    FILE *rez;
    rez = fopen("rez.txt", "wt");

    for(int i = 0; i < 1; i++){
        for(int j = 0; j < 1; j ++){
            for(int k = 0; k < 1; k++){
            fprintf(rez ,"%5d  %5d  %5d     %5d  %5d  %5d     %5d  %5d  %5d\n", dep[0][0], dep[0][1], dep[0][2], dep1[0][0], dep1[0][1], dep1[0][2], res[0][0],res[i][1],res[0][2]);
            fprintf(rez ,"%5d  %5d  %5d  x  %5d  %5d  %5d  =  %5d  %5d  %5d\n", dep[1][0], dep[1][1], dep[1][2], dep1[1][0], dep1[1][1], dep1[1][2], res[1][0],res[1][1],res[1][2]);
            fprintf(rez ,"%5d  %5d  %5d     %5d  %5d  %5d     %5d  %5d  %5d\n", dep[2][0], dep[2][1], dep[2][2], dep1[2][0], dep1[2][1], dep1[2][2], res[2][0],res[2][1],res[2][2]);
            }
        }
    }
fclose(rez);
} 
