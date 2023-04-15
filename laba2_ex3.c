#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int size) {
    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
printf("\n");
}

void append(int** arr, int* size, int value) {
    
    (*size)++;
    *arr = (int*) realloc(*arr, (*size) * sizeof(int));
    (*arr)[(*size) - 1] = value;

}

void insert(int** arr, int* size, int index, int value) {
    
    (*size)++;
    *arr = (int*) realloc(*arr, (*size) * sizeof(int));
    
    for (int i = (*size) - 1; i > index; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    
    (*arr)[index] = value;

}

int main() {

printf("Динамический массив с перераспределением\n");

int size;

printf("Введите начальный размер массива: ");
scanf("%d", &size);

int* arr = (int*) malloc(size * sizeof(int));

printf("Введите %d целых чисел, чтобы заполнить массив:\n", size);

for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
}

print(arr, size);

// Тесты для добавления

printf("Добавление 10 к массиву\n");
append(&arr, &size, 10);
print(arr, size);

printf("Добавление 20 к массиву\n");
append(&arr, &size, 20);
print(arr, size);

printf("Добавление 30 к массиву\n");
append(&arr, &size, 30);
print(arr, size);

printf("Добавление 40 к массиву\n");
append(&arr, &size, 40);
print(arr, size);

printf("Добавление 50 к массиву\n");
append(&arr, &size, 50);
print(arr, size);

// Тесты для вставки

printf("Вставка 15 на место 1 элемента\n");
insert(&arr, &size, 1, 15);
print(arr, size);

printf("Вставка 25 на место 3 элемента\n");
insert(&arr, &size, 3, 25);
print(arr, size);

printf("Вставка 35 на место 5 элемента\n");
insert(&arr, &size, 5, 35);
print(arr, size);

printf("Вставка 45 на место 7 элемента\n");
insert(&arr, &size, 7, 45);
print(arr, size);

printf("Вставка 55 на место 9 элемента\n");
insert(&arr, &size, 9, 55);
print(arr, size);

free(arr);

return 0;
}