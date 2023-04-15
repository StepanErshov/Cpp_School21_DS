#include <stdio.h>


int maxLenght(char);

char arr[] = {'H', 'e', 'l', 'l', 'l','o', 'o', 'l','l','l','l','l','o','o','o','\0'};
int i = 0, count = 0;

int main(){
    char letter;
    printf("Введите букву:");
    scanf("%c", &letter);
    printf("Максимальная длинна из %c элементов равна %d", letter ,maxLenght(letter));
    return 0;
}
int maxLenght(char letter){
    int max = 0;
    for (int i = 0; i < sizeof(arr); i++){
        if (arr[i] == letter) {
            count++;
            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
        }
    }
    return max;
}


