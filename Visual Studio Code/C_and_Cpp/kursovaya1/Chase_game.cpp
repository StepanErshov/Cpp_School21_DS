#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct Point2D {
  int x, y;

  Point2D(int x = 0, int y = 0) : x(x), y(y) {}
};

class Character {
protected:
  Point2D position;

public:
  Character(int x, int y) : position(x, y) {}

  virtual void move() = 0;

  Point2D getPosition() const { return position; }
};

class Prey : public Character {
public:
  Prey(int x, int y) : Character(x, y) {}

  void move() override;
};

class Predator : public Character {
public:
  Predator(int x, int y) : Character(x, y) {}

  void move() override;
};

class Arena {
private:
  static constexpr int WIDTH = 30;
  static constexpr int HEIGHT = 30;
  static constexpr int MOVES_LIMIT = 100;

  Point2D preyPosition;
  Point2D predatorPosition;

  static Arena *instance;

  Arena() : preyPosition(WIDTH / 2, HEIGHT / 2), predatorPosition(0, 0) {}

public:
  static Arena &getInstance() {
    if (!instance) {
      instance = new Arena();
    }
    return *instance;
  }

  Point2D getPreyPosition() const { return preyPosition; }
  Point2D getPredatorPosition() const { return predatorPosition; }

  static int getWidth() { return WIDTH; }
  static int getHeight() { return HEIGHT; }

  void startGame();
};

Arena *Arena::instance = nullptr;

void Prey::move() {
  int dx = 0, dy = 0;
  char key = _getch();
  switch (key) {
  case 'w':
    dy = -1;
    break;
  case 's':
    dy = 1;
    break;
  case 'a':
    dx = -1;
    break;
  case 'd':
    dx = 1;
    break;
  case 'q':
    dx = -1;
    dy = -1;
    break;
  case 'e':
    dx = 1;
    dy = -1;
    break;
  case 'z':
    dx = -1;
    dy = 1;
    break;
  case 'c':
    dx = 1;
    dy = 1;
    break;
  }
  position.x += dx;
  position.y += dy;

  if (position.x < 0)
    position.x = 0;
  if (position.y < 0)
    position.y = 0;
  if (position.x >= Arena::getWidth())
    position.x = Arena::getWidth() - 1;
  if (position.y >= Arena::getHeight())
    position.y = Arena::getHeight() - 1;
}

void Predator::move() {
  int predX = position.x;
  int predY = position.y;
  Point2D preyPos = Arena::getInstance().getPreyPosition();
  int preyX = preyPos.x;
  int preyY = preyPos.y;

  int dx = abs(predX - preyX);
  int dy = abs(predY - preyY);
  int distance = rand() % 3 + 1;

  if (dx > dy) {
    int moveDirection = (predX < preyX) ? 1 : -1;
    position.x += moveDirection * distance;
  } else {
    int moveDirection = (predY < preyY) ? 1 : -1;
    position.y += moveDirection * distance;
  }

  if (position.x < 0)
    position.x = 0;
  if (position.y < 0)
    position.y = 0;
  if (position.x >= Arena::getWidth())
    position.x = Arena::getWidth() - 1;
  if (position.y >= Arena::getHeight())
    position.y = Arena::getHeight() - 1;
}

void Arena::startGame() {
  srand(time(nullptr));
  int movesLeft = MOVES_LIMIT;

  while (movesLeft > 0) {
    system("cls");
    for (int y = 0; y < HEIGHT; ++y) {
      for (int x = 0; x < WIDTH; ++x) {
        if (x == preyPosition.x && y == preyPosition.y)
          std::cout << "$ ";
        else if (x == predatorPosition.x && y == predatorPosition.y)
          std::cout << "@ ";
        else
          std::cout << ". ";
      }
      std::cout << std::endl;
    }

    Prey prey(preyPosition.x, preyPosition.y);
    Predator predator(predatorPosition.x, predatorPosition.y);
    prey.move();
    predator.move();
    preyPosition = prey.getPosition();
    predatorPosition = predator.getPosition();

    if (abs(preyPosition.x - predatorPosition.x) <= 1 &&
        abs(preyPosition.y - predatorPosition.y) <= 1) {
      std::cout << "Game over! You got caught!" << std::endl;
      break;
    }

    _getch();
    --movesLeft;
  }

  if (movesLeft == 0)
    std::cout << "Game over! The moves are over." << std::endl;
}

int main() {
  Arena::getInstance().startGame();
  return 0;
}
