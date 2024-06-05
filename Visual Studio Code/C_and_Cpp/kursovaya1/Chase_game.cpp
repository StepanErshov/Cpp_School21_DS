#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Point2D {
public:
  int x;
  int y;

  Point2D(int x, int y) : x(x), y(y) {}

  int getX() const { return x; }
  int getY() const { return y; }
};

class Character {
protected:
  Point2D position;

public:
  Character(int x, int y) : position(x, y) {}

  virtual void move(char key) = 0;

  Point2D getPosition() const { return position; }
};

enum PlayerType { PREY, PREDATOR };

class Arena {
private:
  static constexpr int WIDTH = 30;
  static constexpr int HEIGHT = 30;
  static constexpr int MOVES_LIMIT = 100;

  Point2D preyPosition;
  Point2D predPosition;
  PlayerType playerType;

public:
  static Arena *instance;

  Arena()
      : preyPosition(WIDTH / 2, HEIGHT / 2), predPosition(0, 0),
        playerType(PREY) {}

  static Arena &getInstance() {
    if (!instance) {
      instance = new Arena();
    }
    return *instance;
  }

  Point2D getPreyPosition() const { return preyPosition; }
  Point2D getPredatorPosition() const { return predPosition; }

  static int getWidth() { return WIDTH; }
  static int getHeight() { return HEIGHT; }

  void setPlayerType(PlayerType type) { playerType = type; }

  void startGame();
};

class Prey : public Character {
public:
  Prey(int x, int y) : Character(x, y) {}

  void move(char key) override {
    switch (key) {
    case 'w':
      position.y -= 1;
      break;
    case 'W':
      position.y -= 1;
      break;
    case 's':
      position.y += 1;
      break;
    case 'S':
      position.y += 1;
      break;
    case 'a':
      position.x -= 1;
      break;
    case 'A':
      position.x -= 1;
      break;
    case 'd':
      position.x += 1;
      break;
    case 'D':
      position.x += 1;
      break;
    case 'q':
      position.x -= 1;
      position.y -= 1;
      break;
    case 'Q':
      position.x -= 1;
      position.y -= 1;
      break;
    case 'e':
      position.x += 1;
      position.y -= 1;
      break;
    case 'E':
      position.x += 1;
      position.y -= 1;
      break;
    case 'z':
      position.x -= 1;
      position.y += 1;
      break;
    case 'Z':
      position.x -= 1;
      position.y += 1;
      break;
    case 'c':
      position.x += 1;
      position.y += 1;
      break;
    case 'C':
      position.x += 1;
      position.y += 1;
      break;
    default:
      std::cout << "Invalid input" << std::endl;
    }

    if (position.x < 0)
      position.x = Arena::getWidth() - 1;
    if (position.y < 0)
      position.y = Arena::getHeight() - 1;
    if (position.x >= Arena::getWidth())
      position.x = 0;
    if (position.y >= Arena::getHeight())
      position.y = 0;
  }

  void moveForPredator() {
    int predX = Arena::getInstance().getPredatorPosition().x;
    int predY = Arena::getInstance().getPredatorPosition().y;
    int preyX = position.getX();
    int preyY = position.getY();

    int dx = abs(predX - preyX);
    int dy = abs(predY - preyY);

    if (dx > dy) {
      int moveDirection = (preyX < predX) ? 1 : ((preyX > predX) ? -1 : 0);
      position = Point2D(preyX - moveDirection, preyY);
    } else {
      int moveDirection = (preyY < predY) ? 1 : ((preyY > predY) ? -1 : 0);
      position = Point2D(preyX, preyY - moveDirection);
    }
    if (position.x < 0)
      position.x = 0;
    if (position.y < 0)
      position.y = 0;
    if (position.x >= Arena::getWidth())
      position.x = Arena::getWidth() - 1;
    if (position.y >= Arena::getHeight())
      position.y = Arena::getWidth() - 1;
  }
};

class Predator : public Character {
public:
  Predator(int x, int y) : Character(x, y) {}

  void move(char key) override {
    switch (key) {
    case 'w':
      position.y -= 1 + (rand() % 3);
      break;
    case 'W':
      position.y -= 1 + (rand() % 3);
      break;
    case 's':
      position.y += 1 + (rand() % 3);
      break;
    case 'S':
      position.y += 1 + (rand() % 3);
      break;
    case 'a':
      position.x -= 1 + (rand() % 3);
      break;
    case 'A':
      position.x -= 1 + (rand() % 3);
      break;
    case 'd':
      position.x += 1 + (rand() % 3);
      break;
    case 'D':
      position.x += 1 + (rand() % 3);
      break;
    case 'q':
      position.x -= 1;
      position.y -= 1;
      break;
    case 'Q':
      position.x -= 1;
      position.y -= 1;
      break;
    case 'e':
      position.x += 1;
      position.y -= 1;
      break;
    case 'E':
      position.x += 1;
      position.y -= 1;
      break;
    case 'z':
      position.x -= 1;
      position.y += 1;
      break;
    case 'Z':
      position.x -= 1;
      position.y += 1;
      break;
    case 'c':
      position.x += 1;
      position.y += 1;
      break;
    case 'C':
      position.x += 1;
      position.y += 1;
      break;
    default:
      std::cout << "Invalid input" << std::endl;
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

  void moveForPrey() {

    int predX = position.getX();
    int predY = position.getY();
    int preyX = Arena::getInstance().getPreyPosition().getX();
    int preyY = Arena::getInstance().getPreyPosition().getY();

    int dx = abs(predX - preyX);
    int dy = abs(predY - preyY);
    int distance = rand() % 3 + 1;

    if (dx > dy) {
      int moveDirection = (predX < preyX) ? 1 : ((predX > preyX) ? -1 : 0);
      position = Point2D(predX + moveDirection * distance, predY);
    } else {
      int moveDirection = (predY < preyY) ? 1 : ((predY > preyY) ? -1 : 0);
      position = Point2D(predX, predY + moveDirection * distance);
    }
  }
};

Arena *Arena::instance = nullptr;

void Arena::startGame() {
  srand(time(nullptr));
  int movesLeft = MOVES_LIMIT;

  while (movesLeft > 0) {
    system("cls");
    std::cout << "+ ";
    for (int i = 0; i < WIDTH; ++i) {
      std::cout << "- ";
    }
    std::cout << "+" << std::endl;
    for (int y = 0; y < HEIGHT; ++y) {
      std::cout << "|";
      for (int x = 0; x < WIDTH; ++x) {
        if (x == preyPosition.x && y == preyPosition.y)
          std::cout << "$ ";
        else if (x == predPosition.x && y == predPosition.y)
          std::cout << "@ ";
        // else if (x == WIDTH - 1 || x == 0)
        //     std::cout << "|";
        else if (y == HEIGHT / 2) {
          std::cout << ". ";
        } else {
          std::cout << "  ";
        }
      }
      std::cout << "|" << std::endl;
    }
    std::cout << "+";
    for (int i = 0; i < WIDTH; ++i) {
      std::cout << "- ";
    }
    std::cout << "+" << std::endl;

    Prey prey(preyPosition.x, preyPosition.y);
    Predator predator(predPosition.x, predPosition.y);

    if (playerType == PlayerType::PREY) {
      prey.move(_getch());
      predator.moveForPrey();
    } else if (playerType == PlayerType::PREDATOR) {
      predator.move(_getch());
      prey.moveForPredator();
    }

    preyPosition = prey.getPosition();
    predPosition = predator.getPosition();

    if (abs(preyPosition.x - predPosition.x) <= 1 &&
        abs(preyPosition.y - predPosition.y) <= 1) {
      std::cout << "Game over You got caught!" << std::endl;
      break;
    }
    --movesLeft;
  }

  if (movesLeft == 0) {
    std::cout << "Game over The moves are over." << std::endl;
  }
}

int main() {
  PlayerType choose;
  int ch;
  std::cout << "Choose hero: \n 1. Predator \n 2. Prey" << std::endl;
  std::cin >> ch;
  if (ch == 1)
    choose = PlayerType::PREDATOR;
  else if (ch == 2)
    choose = PlayerType::PREY;
  Arena::getInstance().setPlayerType(choose);
  Arena::getInstance().startGame();
  return 0;
}