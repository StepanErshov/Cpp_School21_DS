#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <stdlib.h>  //Данная библиотека для многих функций Си нужна, но не здесь
#include <locale.h> // Библиотека для указания локации (региональной кодировки) для Visual Studio
#include <stdbool.h> 

int bissectrice(double, double);
int vertical(double, double);
int horizontal(double, double);

int main() {

  double x = -5;
  double y = 5;

  printf("Введите значение x: ");
  scanf("%d",&x);
  printf("Введите значение y: ");
  scanf("%d",&y);

  printf("%d", (!vertical(x, y) && !horizontal(x, y) && bissectrice(x, y)) || (vertical(x, y) && horizontal(x, y)));
  return 0;
}

int bissectrice(double x, double y) {

  bool doesItBelong = true;
  doesItBelong = (y <= -x);
  return doesItBelong;
}


int vertical(double x, double y) {

  bool doesItBelong = true;
  doesItBelong = (x > 4);
  return doesItBelong;
}
int horizontal(double x, double y) {
  
  bool doesItBelong = true;
  doesItBelong = (y > 3);
  return doesItBelong;
}

//Тесты (вклюачет ли код границу закрашенной области в допустимое значение): 
// (0,0)
// (4,3)
// (4,5)
// (5,3)
// (7,3)

// (-1,1)
// (1,-1)
// (-5,5) (False)
// (5,-5) (False)
// (-5,3)