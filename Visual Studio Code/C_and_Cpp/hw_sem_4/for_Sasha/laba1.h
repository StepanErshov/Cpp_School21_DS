#ifndef LABA1
#define LABA1

class cashRegister {
private:
  int cashOnHand;

public:
  cashRegister() : cashOnHand(0) {}
  cashRegister(int amount) : cashOnHand(amount) {}

  int getCurrentBalance() { return cashOnHand; }

  void acceptAmount(int amount) { cashOnHand += amount; }
};

class dispenserType {
private:
  int numberOfItems;
  int typeCost;

public:
  dispenserType() : numberOfItems(50), typeCost(10) {}
  dispenserType(int items, int cost) : numberOfItems(items), typeCost(cost) {}

  int getNoOfItems() { return numberOfItems; }

  int getCost() { return typeCost; }

  void makeSale() {
    if (numberOfItems > 0) {
      numberOfItems--;
    }
  }
};

#endif