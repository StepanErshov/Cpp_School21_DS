#include <stdio.h>

int main() {
    FILE *file = fopen("test_tabulation.txt", "w");
    if (file == NULL) {
        perror("s21_cat: ");
        return 1;
    }
    fprintf(file, "Tabulation: \t");
    fclose(file);

    char *filename = "test_tabulation.txt";
    char command[256]; 
    sprintf(command, "./s21_cat -T \"%s\"", filename);
    system(command);

    return 0;
}
