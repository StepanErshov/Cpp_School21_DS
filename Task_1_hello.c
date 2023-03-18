#include <stdio.h>
#define MAX 20

int main(){
    char str[MAX];
    printf("Enter who you want to say hello to: ");
    fgets(str, MAX, stdin);
    printf("Hello, %s",str);
    return 0;

}

/*
Задания:

    1. Скомпилируйте программу через терминал с выдачей файлов промежуточных этапов.
        (Preprocess -> Compile -> Assemble -> Link, см. help для gcc) 
        Что происходит на каждом этапе?

    2. Скомпилируйте программу в VS Code. 

    3. Сломайте эту программу.
        Удалите последовательно из кода программы символы: ;, ), {
        И попробуйте выполнить программу. 
        Проанализируйте ошибки на которые укажет компилятор
    
    4. Доработайте программу
        Обеспечьте возможность передачи аргумента при запуске Task.exe из терминала
        Используйте аргумент как имя для приветствии 
        (вместо "Hello, World!", должно быть "Hello, <Параметр>!")

*/