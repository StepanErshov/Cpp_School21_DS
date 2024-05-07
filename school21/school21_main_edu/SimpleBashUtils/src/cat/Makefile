NAME = s21_cat

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_FILES = s21_cat.c

INCLUDES = -I.

TEST_FILES = test_*.c

TEST_SCRIPT = run_tests.sh

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRC_FILES)

test: ./run_tests.sh
	@echo "Start..."
	./run_tests.sh
clean:
	rm -f $(NAME)

all: test clean
