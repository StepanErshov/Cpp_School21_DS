#ifndef LABA1
#define LABA1
#include <clocale>
#include <iostream>
#include <vector>

class cashRegister {
private:
  int cashOnHand;

public:
  cashRegister() : cashOnHand(500) {}
  cashRegister(int amount) : cashOnHand(amount) {}

  int getCurrentBalance() { return cashOnHand; }

  void acceptAmount(int amount) { cashOnHand += amount; }
};

class dispenserType {
private:
  int numberOfItems;
  int typeCost;

public:
  dispenserType(int items, int cost) : numberOfItems(items), typeCost(cost) {}

  int getNoOfItems() { return numberOfItems; }

  int getCost() { return typeCost; }

  void makeSale() {
    if (numberOfItems > 0) {
      numberOfItems--;
    }
  }
};

void processTransaction(std::vector<dispenserType> &dispensers,
                        cashRegister &cashRegister);
void showMenu();

#endif