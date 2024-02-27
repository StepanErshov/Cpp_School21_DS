#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <locale.h> // Библиотека для указания локации (региональной кодировки)

/*
На вход (double x, double y)

3 функции:
Bissectrice(double x, double y)
Vertical(double x, double y)
Horizontal(double x, double y)

выход int
*/

int Bissectrice(double, double);
int Vertical(double, double);
int Horizontal(double, double);

int main(){
    double x = 5.;
    double y = 4.;
    printf("%d",Bissectrice(x, y) || Vertical(x, y) && Horizontal(x, y));
    return 0;
}
int Bissectrice(double x, double y){
    int res = -1;
    res = (y <= -x);
    return res;
}
/*
    ! не
    && конъюнкция
    || дизъюнкция
*/
int Vertical(double x, double y){
    int res = -1;
    res = (x > 4); 
    return res;
}
int Horizontal(double x, double y){
    int res = -1;
    res = (y > 3);
    return res;
}

