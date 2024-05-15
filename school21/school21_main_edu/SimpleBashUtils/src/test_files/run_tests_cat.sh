#!/bin/bash

PROGRAM_PATH="../cat/s21_cat"

TEST_FILES="test_*.txt"

FLAGS1="-n"
FLAGS2="-b"
FLAGS3="-e"
FLAGS4="-t"
FLAGS5="-s"
FLAGS6="-nbets"

for file in $TEST_FILES; do
    echo  -e "\n\n Running real cat test on $file\n"
    cat $FLAGS1 $file
    cat $FLAGS2 $file
    cat $FLAGS3 $file
    cat $FLAGS4 $file
    cat $FLAGS5 $file
    cat $FLAGS6 $file
    echo -e "\n\n Running my cat\n"
    $PROGRAM_PATH $FLAGS1 $file
    $PROGRAM_PATH $FLAGS2 $file
    $PROGRAM_PATH $FLAGS3 $file
    $PROGRAM_PATH $FLAGS4 $file
    $PROGRAM_PATH $FLAGS5 $file
    $PROGRAM_PATH $FLAGS6 $file
done

echo -e "\n\nAll tests completed.\n"
