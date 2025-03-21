#!/bin/bash

echo""
echo "************************************* TESTING 2 ELEMENTS ***************************************"

./push_swap 54 45 | wc -l
./push_swap 54 45 | ./checker_linux 54 45

echo""
echo "************************************* TESTING 3 ELEMENTS ***************************************"

./push_swap 54 45 60 | wc -l
./push_swap 54 45 60 | ./checker_linux 54 45 60

echo""
echo "************************************* TESTING 4 ELEMENTS ***************************************"

./push_swap 54 45 60 12| wc -l
./push_swap 54 45 60 12| ./checker_linux 54 45 60 12

echo""
echo "************************************* TESTING 5 ELEMENTS ***************************************"

./push_swap 54 45 60 12 9| wc -l
./push_swap 54 45 60 12 9| ./checker_linux 54 45 60 12 9

echo ""
echo "************************************* TESTING 100 ELEMENTS *************************************"

echo "Worst case sorting of 100 elements:"
ARG=$(seq 100 -1 1 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo ""
echo "Random sorting tests for 100 elements:"
for i in {1..5}; do
  ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  ./push_swap $ARG | wc -l
  ./push_swap $ARG | ./checker_linux $ARG
done

echo ""
echo "************************************* TESTING 500 ELEMENTS *************************************"

echo "Worst case sorting of 500 elements:"
ARG=$(seq 500 -1 1 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

echo "Random sorting tests for 500 elements:"
for i in {1..5}; do
  ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
  ./push_swap $ARG | wc -l
  ./push_swap $ARG | ./checker_linux $ARG
done
