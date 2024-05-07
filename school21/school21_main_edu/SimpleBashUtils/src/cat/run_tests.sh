#!/bin/bash

PROGRAM_PATH="./s21_cat"

TEST_FILES="test_*.txt"

FLAGS1="-n"
FLAGS2="-b"
FLAGS3="-e"
FLAGS4="-t"
FLAGS5="-s"

for file in $TEST_FILES; do
    echo "Running test on $file"
    $PROGRAM_PATH $FLAGS1 $file
    $PROGRAM_PATH $FLAGS2 $file
    $PROGRAM_PATH $FLAGS3 $file
    $PROGRAM_PATH $FLAGS4 $file
    $PROGRAM_PATH $FLAGS5 $file
done

echo "All tests completed."
