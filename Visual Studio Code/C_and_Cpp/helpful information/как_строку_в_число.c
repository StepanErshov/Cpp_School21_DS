#include <stdio.h>   //Для printf()
#include <stdlib.h>  //Для atoi()

int main (void)
{   
   char *Str = "652.23brrt"; //Строка для преобразования
   int Num = 0;                //Переменная для записи результата
   
   //Преобразование строки в число типа int
   Num = atoi (Str);
   
   //Вывод результата преобразования
   printf ("%d\n",Num);
   
   //Завершение работы программы
   return 0; 
}
