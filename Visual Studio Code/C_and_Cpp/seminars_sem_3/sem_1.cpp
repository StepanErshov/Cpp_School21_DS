#define _CTR_SECURE_NO_WARNINGS
#include "stdio.h" 
#include "math.h"
#include <cmath> 
#include <iostream>

using namespace std;

int main(){
    int carrots = 23;
    int a = 0;

    printf("I heve %d carrots!", carrots);
    cout << "I have" << carrots << "carrots!" <<  std::endl;
    std::cin >> a;
    std::cout << std::endl;
    std::cout << a;
    scanf("%d", &a);

    return 0;
}