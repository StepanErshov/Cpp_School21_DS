#include <stdio.h>

int binomial(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return binomial(n - 1, k - 1) + binomial(n - 1, k);
    }
}

void print_pascal_triangle(int n) {
    int pascal_triangle[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            pascal_triangle[i][j] = binomial(i, j);
            printf("%d ", pascal_triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Введите степень бинома Ньютона: ");
    scanf("%d", &n);
    print_pascal_triangle(n);
    return 0;
}