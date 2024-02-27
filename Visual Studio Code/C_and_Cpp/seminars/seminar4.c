#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//Create + open = fopen()

//read
    //fscanf("%",)
    //fgets()
    //fgetc()
    //fread()  => (.bin)
//write
    //fprintf()
    //fputs()
    //fputc()
    //fwrite() => (.bin)
//navigate
    //ftell
    //rewind()
    //fseek()


//Close = fclose()
int i = 0;

int main(int argc, char* argv[]){
    FILE* my_file = fopen("text_course.txt", "r");
    printf("%ld\n",ftell(my_file));
    int a = 0;
    int b = 0;
    int c = 0;
    // fscanf(my_file, "%d%d%d", &a, &b, &c);
    char string[15];
    fgets(string, 10, my_file);
    printf("%ld\n",ftell(my_file));
    printf("%s\n", string);
    char last_sym = fgetc(my_file);
    printf("%c\n", last_sym);

    fclose(my_file);
    // printf("%d\n", a);
    // printf("%d\n", b);
    // printf("%d\n", c);
    return 0;
}