#include <iostream>

int main() {
    int var = 42;

    int* ptr = &var;

    std::cout << var << std::endl;

    std::cout << &var << std::endl;

    std::cout << ptr << std::endl;

    return 0;
}