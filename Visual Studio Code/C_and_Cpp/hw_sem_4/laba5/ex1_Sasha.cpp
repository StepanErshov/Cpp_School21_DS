#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec;
    std::ifstream file("data.txt");
    int num;

    while (file >> num) {
        vec.push_back(num);
    }

    file.close();
    std::cout << "Reading from file is complete. Vector contains " << vec.size() << " elements.\n";

    std::reverse(vec.begin(), vec.end());
std::cout << "After revrse: ";
for (int num : vec) {
    std::cout << num << " ";
}
std::cout << "\n";

auto min_it = std::min_element(vec.begin(), vec.end());
std::cout << "Min element: " << *min_it << "\n";

vec.erase(std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2 == 0; }), vec.end());
std::cout << "After delete even: ";
for (int num : vec) {
    std::cout << num << " ";
}
std::cout << "\n";

std::sort(vec.begin(), vec.end()); // Для возрастающей последовательности
// std::sort(vec.rbegin(), vec.rend()); // Для убывающей последовательности
std::cout << "After sort: ";
for (int num : vec) {
    std::cout << num << " ";
}

std::cout << "\n";
int insert_value = 5; // Пример значения для вставки
auto insert_it = std::lower_bound(vec.begin(), vec.end(), insert_value);
vec.insert(insert_it, insert_value);
std::cout << "After inserts: ";
for (int num : vec) {
    std::cout << num << " ";
}
std::cout << "\n";

int find_value = 13; // Пример значения для поиска
auto find_it = std::find(vec.begin(), vec.end(), find_value);
if (find_it != vec.end()) {
    std::cout << "Element found, index: " << std::distance(vec.begin(), find_it) << "\n";
} else {
    std::cout << "Element not found\n";
}

vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
std::cout << "After delete duplicates: ";
for (int num : vec) {
    std::cout << num << " ";
}
std::cout << "\n";

}
