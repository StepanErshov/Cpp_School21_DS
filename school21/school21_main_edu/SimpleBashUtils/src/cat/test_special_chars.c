#include <stdio.h>

int main() {
    FILE *file = fopen("test_special_chars.txt", "w");
    if (file == NULL) {
        perror("s21_cat: ");
        return 1;
    }
    fprintf(file, "Special characters: \n\t\n\r");
    fclose(file);

    char *filename = "test_special_chars.txt";
    char command[256]; 
    sprintf(command, "./s21_cat -v \"%s\"", filename);
    system(command); 

    return 0;
}
