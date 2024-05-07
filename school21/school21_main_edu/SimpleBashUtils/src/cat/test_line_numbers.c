#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file = fopen("test_line_numbers.txt", "w");
    if (file == NULL) {
        perror("s21_cat: ");
        return 1;
    }
    fprintf(file, "Line 1\nLine 2\nLine 3\n");
    fclose(file);

    char *filename = "test_line_numbers.txt";
    char command[256]; 
    sprintf(command, "./s21_cat -n -b \"%s\"", filename); 
    system(command); 
    return 0;
}
