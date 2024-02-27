#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <copy>\n", argv[0]);
        return 1;
    }

    FILE *original_file = fopen(argv[1], "rb");
    if (original_file == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        return 1;
    }

    FILE *copy_file = fopen(argv[2], "wb");
    if (copy_file == NULL) {
        printf("Error: cannot create file %s\n", argv[2]);
        fclose(original_file);
        return 1;
    }

    // Установливаем индикатор позиции файла в конец файла
    fseek(original_file, 0, SEEK_END);

    // Получаем размер файла
    long filesize = ftell(original_file);

    // Наведение указателя позиции файла обратно на начало файла
    fseek(original_file, 0, SEEK_SET);

    // Выделяем память для чтения файла
    char *buffer = malloc(filesize);

    // Копируем файл
    size_t bytes_read = fread(buffer, sizeof(char), filesize, original_file);
    fwrite(buffer, sizeof(char), bytes_read, copy_file);

    // Освобождаем память
    free(buffer);

    // Закрываем файлы
    fclose(original_file);
    fclose(copy_file);

    return 0;
}

/*Программа открывает два файла: оригинальный файл для чтения и копию файла для записи. 
Она вычисляет размер файла, выделяет память для прочтения файла и затем копирует содержимое одного файла в другой, 
не считывая его содержимое. Наконец, программа освобождает память, закрывает файлы и завершает работу.*/