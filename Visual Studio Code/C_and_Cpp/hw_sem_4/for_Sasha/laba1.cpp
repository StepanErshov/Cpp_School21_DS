#include "laba1.h"
#include <iostream>

void showSelection() {
  std::cout << "1. Candy\n2. Chips\n3. Chewing gum\n4. Cookies\n";
}

void sellProduct(dispenserType &dispenser, cashRegister &cash) {
  int choice;
  std::cout << "Select product: ";
  std::cin >> choice;

  switch (choice) {
  case 1:
    if (dispenser.getNoOfItems() > 0) {
      std::cout << "Price: " << dispenser.getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispenser.getCost()) {
        dispenser.makeSale();
        cash.acceptAmount(amount - dispenser.getCost());
        std::cout << "Sales! Cash balance: " << cash.getCurrentBalance()
                  << " rub.\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  case 2:
    // Обработка продажи чипсов
    if (dispenser.getNoOfItems() > 0) {
      std::cout << "Price: " << dispenser.getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispenser.getCost()) {
        dispenser.makeSale();
        cash.acceptAmount(amount - dispenser.getCost());
        std::cout << "Sales! Cash balance: " << cash.getCurrentBalance()
                  << " rub.\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  case 3:
    // Обработка продажи жвачки
    if (dispenser.getNoOfItems() > 0) {
      std::cout << "Price: " << dispenser.getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispenser.getCost()) {
        dispenser.makeSale();
        cash.acceptAmount(amount - dispenser.getCost());
        std::cout << "Sales! Cash balance: " << cash.getCurrentBalance()
                  << " rub.\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  case 4:
    // Обработка продажи печенья
    if (dispenser.getNoOfItems() > 0) {
      std::cout << "Price: " << dispenser.getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispenser.getCost()) {
        dispenser.makeSale();
        cash.acceptAmount(amount - dispenser.getCost());
        std::cout << "Sales! Cash balance: " << cash.getCurrentBalance()
                  << " rub.\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  default:
    std::cout << "n/a\n";
    break;
  }
}

int main() {
  cashRegister cash;
  dispenserType dispenserCandies(50, 10); // Конфеты
  dispenserType dispenserChips(50, 15);   // Чипсы
  dispenserType dispenserGum(50, 20);     // Жвачка
  dispenserType dispenserCookies(50, 25); // Печенье

  while (true) {
    showSelection();
    sellProduct(dispenserCandies, cash);
    sellProduct(dispenserChips, cash);
    sellProduct(dispenserGum, cash);
    sellProduct(dispenserCookies, cash);
  }

  return 0;
}