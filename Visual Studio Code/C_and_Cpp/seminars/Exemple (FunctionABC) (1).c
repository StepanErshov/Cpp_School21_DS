#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <locale.h> // Библиотека для указания локации (региональной кодировки)

void A();
void B();
void C();

int main()
{
    setlocale(LC_ALL, "Rus");

    printf("main() CALL   ->\n");
    A();
    printf("tmain() RETURN <-\n");

    return 0;
}

void A() {
    printf("\t\t   A() CALL   ->\n");
    B();
    printf("\t\t   A() RETURN <-\n");
}

void B() {
    printf("\t\t\t\t   B() CALL   ->\n");
    C();
    printf("\t\t\t\t   B() RETURN <-\n");
}

void C() {
    printf("\t\t\t\t\t\t   C() CALL   ->\n");
    printf("\t\t\t\t\t\t   C() RETURN <-\n");
}




/*
Упражнение 1.

Перепешите представленный пример в виде рекурсивного вызова функции А() 
с наперёд заданной глубиной рекурсии (запрашивать у пользователя).

*/