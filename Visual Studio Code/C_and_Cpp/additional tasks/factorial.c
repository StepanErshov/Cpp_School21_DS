#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

long long factorial(int n) {
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}


int main() {
for (int i = 1; i <= 20; i++) {
    printf("%d! = %lld\n", i, factorial(i));
    }
    return 0;
}