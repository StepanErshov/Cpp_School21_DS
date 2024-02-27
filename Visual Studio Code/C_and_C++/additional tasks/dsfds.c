#include <stdio.h>

int countFragments(char* text) {
    int count = 0;
    int i = 0;

    // Проверяем каждый символ текста
    while (text[i] != '\0') {
        // Если текущий символ - перевод строки, увеличиваем счетчик фрагментов
        if (text[i] == '\n') {
            count++;
        }

        i++;
    }

    // Если текст заканчивается не переводом строки, добавляем еще один фрагмент
    if (i > 0 && text[i - 1] != '\n') {
        count++;
    }

    return count;
}

int main() {
    // Выделяем память для хранения текста
    char* text = malloc(100001 * sizeof(char));

    // Считываем текст
    fgets(text, 100001, stdin);

    // Считаем количество фрагментов и выводим результат
    int fragmentCount = countFragments(text);
    printf("%d\n", fragmentCount);

    // Освобождаем память
    free(text);

    return 0;
}