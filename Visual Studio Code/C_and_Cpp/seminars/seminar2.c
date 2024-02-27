#include <stdio.h>
#include <locale.h>

void example_function();
static int a;

int main(){
    setlocale(LC_ALL, "Rus");

    printf("Hello world\n");

    for(int i = 0; i < 10; i++){
        example_function();
        }
    
    return 0;
}

void example_function(){
    static int static_variable = 0;
    int variable = 0;
    
    static_variable++;
    variable++;
    a++;
    printf("Static variable value: %d\n", static_variable);
    printf("Variable value: %d\n", variable);
    printf("A value: %d\n", a);
}