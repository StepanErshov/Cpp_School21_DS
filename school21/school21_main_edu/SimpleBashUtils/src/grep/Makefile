NAME = s21_grep

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_FILES = s21_grep.c

INCLUDES = -I.

TEST_SCRIPT = run_tests.sh

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRC_FILES)

test: ../test_files/run_tests_grep.sh
	@echo "Start..."
	../test_files/run_tests_grep.sh
clean:
	rm -f $(NAME)

all: test clean
