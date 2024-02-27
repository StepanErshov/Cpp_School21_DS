#include "laba1.h"

void showMenu() {
  std::cout << "1. Candy\n2. Chips\n3. Chewing gum\n4. Cookies\n";
}

void processTransaction(std::vector<dispenserType> &dispensers,
                        cashRegister &cashRegister) {
  int choice;
  std::cout << "Select product: ";
  std::cin >> choice;

  switch (choice) {
  case 1:
    if (dispensers[0].getNoOfItems() > 0) {
      std::cout << "Price: " << dispensers[0].getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispensers[0].getCost()) {
        dispensers[0].makeSale();
        cashRegister.acceptAmount(amount - dispensers[0].getCost());
        std::cout << "Product sold!\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  case 2:
    if (dispensers[1].getNoOfItems() > 0) {
      std::cout << "Price: " << dispensers[1].getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispensers[1].getCost()) {
        dispensers[1].makeSale();
        cashRegister.acceptAmount(amount - dispensers[1].getCost());
        std::cout << "Product sold!\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  case 3:
    if (dispensers[2].getNoOfItems() > 0) {
      std::cout << "Price: " << dispensers[2].getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispensers[2].getCost()) {
        dispensers[2].makeSale();
        cashRegister.acceptAmount(amount - dispensers[2].getCost());
        std::cout << "Product sold!\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  case 4:
    if (dispensers[3].getNoOfItems() > 0) {
      std::cout << "Price: " << dispensers[3].getCost() << " rub.\n";
      int amount;
      std::cout << "Enter the amount: ";
      std::cin >> amount;
      if (amount >= dispensers[3].getCost()) {
        dispensers[3].makeSale();
        cashRegister.acceptAmount(amount - dispensers[3].getCost());
        std::cout << "Product sold!\n";
      } else {
        std::cout << "Insufficient funds.\n";
      }
    } else {
      std::cout << "Product unavailable.\n";
    }
    break;
  default:
    std::cout << "Wrong choice.\n";
    break;
  }
}

int main() {
  setlocale(LC_ALL, "Russian_Russia.1251");

  std::vector<dispenserType> dispensers = {
      dispenserType(50, 10), dispenserType(50, 15), dispenserType(50, 20),
      dispenserType(50, 25)};

  cashRegister cashRegister;

  showMenu();
  processTransaction(dispensers, cashRegister);

  return 0;
}
