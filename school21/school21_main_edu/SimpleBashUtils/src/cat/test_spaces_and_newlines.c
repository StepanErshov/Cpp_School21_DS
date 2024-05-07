#include <stdio.h>

int main() {
    FILE *file = fopen("test_spaces_and_newlines.txt", "w");
    if (file == NULL) {
        perror("s21_cat: ");
        return 1;
    }
    fprintf(file, "Spaces and newlines:\n\n\n\n");
    fclose(file);

    char *filename = "test_spaces_and_newlines.txt";
    char command[256]; 
    sprintf(command, "./s21_cat -s \"%s\"", filename);
    system(command); 
    return 0;
}
