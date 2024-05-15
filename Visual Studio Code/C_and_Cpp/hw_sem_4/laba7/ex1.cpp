#include <chrono>
#include <iostream>
#include <list>
#include <vector>

int main() {

  const int N = 10000; // Количество элементов для вставки и удаления

  // Создаем вектор
  std::vector<int> vec(N);

  // Создаем список
  std::list<int> lst;

  // Заполняем оба контейнера рандомными значениями
  for (int i = 0; i < N; ++i) {
    lst.push_back(rand());
    vec[i] = rand();
  }

  // Выводим объем памяти, занимаемый каждым из контейнеров
  std::cout << "Vector uses " << sizeof(vec) << " bytes\n";
  std::cout << "List uses " << sizeof(lst) << " bytes\n";

  // Измерение времени для вектора
  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < N; ++i) {
    vec.insert(vec.begin() + vec.size() / 2,
               i); // Вставка элемента в середину вектора
  }
  for (int i = 0; i < N; ++i) {
    vec.erase(vec.begin() +
              vec.size() / 2); // Удаление элемента из середины вектора
  }
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> vecDuration = end - start;

  // Измерение времени для списка
  start = std::chrono::steady_clock::now();
  for (int i = 0; i < N; ++i) {
    auto it = lst.begin();
    std::advance(it, lst.size() / 2);
    lst.insert(it, i); // Вставка элемента в середину списка
  }
  for (int i = 0; i < N; ++i) {
    auto it = lst.begin();
    std::advance(it, lst.size() / 2);
    lst.erase(it); // Удаление элемента из середины списка
  }
  end = std::chrono::steady_clock::now();
  std::chrono::duration<double> lstDuration = end - start;

  // Вывод результатов
  std::cout << "Operation time for a vector: " << vecDuration.count()
            << " seconds\n";
  std::cout << "Operation time for a list: " << lstDuration.count()
            << " seconds\n";

  return 0;
}

/*
В общем, используйте вектор, когда вас не волнует, какой тип последовательного
контейнера вы используете, но если вы выполняете много вставок или стираний из
любого места контейнера, кроме конца, вам понадобится использовать список. Или,
если вам нужен произвольный доступ, вам понадобится вектор, а не список. Помимо
этого, естественно, бывают случаи, когда вам понадобится то или иное в
зависимости от вашей поставленной задачи.
*/