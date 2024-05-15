#!/bin/bash

PROGRAM_PATH="../grep/s21_grep"

TEST_FILES="/Users/squanclo/Documents/C3_SimpleBashUtils-1/src/test_files/test_*.txt"

SAMPLE_FILE="sample.txt"

FLAGS1="-i"
FLAGS2="-v"
FLAGS3="-e"
FLAGS4="-c"
FLAGS5="-l"
FLAGS6="-n"
FLAGS7="-h"
FLAGS8="-s"
FLAGS9="-f"
FLAGS10="-o"
FLAGS11="-iv"
FLAGS12="-in"
FLAGS13="-lh"
FLAGS14="-ince"
FLAGS15="-hc"



echo "---------------------------Test-1---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS1 test on $file:"
    grep $FLAGS1  "l" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS1 test on $file:"
    $PROGRAM_PATH $FLAGS1 "l" $file
    echo -e "\n"
done

echo "---------------------------Test-2---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS2 test on $file:"
    grep $FLAGS2 "1" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS2 test on $file:"
    $PROGRAM_PATH $FLAGS2 "1" $file
    echo -e "\n"
done

echo "---------------------------Test-3---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS3 test on $file:"
    grep $FLAGS3 "1" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS3 test on $file:"
    $PROGRAM_PATH $FLAGS3 "1" $file
    echo -e "\n"
done

echo "---------------------------Test-4---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS4 test on $file:"
    grep $FLAGS4 "L" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS4 test on $file:"
    $PROGRAM_PATH $FLAGS4 "L" $file
    echo -e "\n"
done

echo "---------------------------Test-5---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS5 test on $file:"
    grep $FLAGS5 "L" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS5 test on $file:"
    $PROGRAM_PATH $FLAGS5 "L" $file
    echo -e "\n"
done

echo "---------------------------Test-6---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS6 test on $file:"
    grep $FLAGS6 "L" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS6 test on $file:"
    $PROGRAM_PATH $FLAGS6 "L" $file
    echo -e "\n"
done

echo "---------------------------Test-7---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS7 test on $file:"
    grep $FLAGS7 "L" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS7 test on $file:"
    $PROGRAM_PATH $FLAGS7 "L" $file
    echo -e "\n"
done

echo "---------------------------Test-8---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS8 test on $file:"
    grep $FLAGS8 "g" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS8 test on $file:"
    $PROGRAM_PATH $FLAGS8 "g" $file
    echo -e "\n"
done

echo "---------------------------Test-9---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS9 test on $file:"
    grep $FLAGS9 $SAMPLE_FILE $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS9 test on $file:"
    $PROGRAM_PATH $FLAGS9 $SAMPLE_FILE $file
    echo -e "\n"
done

echo "---------------------------Test-10---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS10 test on $file:"
    grep $FLAGS10 "i" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS10 test on $file:"
    $PROGRAM_PATH $FLAGS10 "i" $file
    echo -e "\n"
done

echo "---------------------------Test-11---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS11 test on $file:"
    grep $FLAGS11 "i" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS11 test on $file:"
    $PROGRAM_PATH $FLAGS11 "i" $file
    echo -e "\n"
done

echo "---------------------------Test-12---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS12 test on $file:"
    grep $FLAGS12 "n" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS12 test on $file:"
    $PROGRAM_PATH $FLAGS12 "n" $file
    echo -e "\n"
done

echo "---------------------------Test-13---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS13 test on $file:"
    grep $FLAGS13 "n" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS13 test on $file:"
    $PROGRAM_PATH $FLAGS13 "n" $file
    echo -e "\n"
done

echo "---------------------------Test-14---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS14 test on $file:"
    grep $FLAGS14 "n" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS14 test on $file:"
    $PROGRAM_PATH $FLAGS14 "n" $file
    echo -e "\n"
done

echo "---------------------------Test-15---------------------------"

for file in $TEST_FILES; do
    echo "Running real grep $FLAGS15 test on $file:"
    grep $FLAGS15 "n" $file
    echo -e "\n"
    echo "Running ./s21_grep $FLAGS15 test on $file:"
    $PROGRAM_PATH $FLAGS15 "n" $file
    echo -e "\n"
done


echo "All tests completed."
