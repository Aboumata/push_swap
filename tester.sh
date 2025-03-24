#!/bin/bash

echo ""
echo "************************************* TESTING 2 ELEMENTS ***************************************"

timeout 5s ./push_swap 54 45 | tee /tmp/ps_output.txt | wc -l
timeout 5s ./push_swap 54 45 | ./checker_linux 54 45

echo ""
echo "************************************* TESTING 3 ELEMENTS ***************************************"

timeout 5s ./push_swap 54 45 60 | tee /tmp/ps_output.txt | wc -l
timeout 5s ./push_swap 54 45 60 | ./checker_linux 54 45 60

echo ""
echo "************************************* TESTING 4 ELEMENTS ***************************************"

timeout 5s ./push_swap 54 45 60 12 | tee /tmp/ps_output.txt | wc -l
timeout 5s ./push_swap 54 45 60 12 | ./checker_linux 54 45 60 12

echo ""
echo "************************************* TESTING 5 ELEMENTS ***************************************"

timeout 5s ./push_swap 54 45 60 12 9 | tee /tmp/ps_output.txt | wc -l
timeout 5s ./push_swap 54 45 60 12 9 | ./checker_linux 54 45 60 12 9

echo ""
echo "************************************* TESTING 100 ELEMENTS *************************************"

echo "Worst case sorting of 100 elements:"
ARG=$(seq 100 -1 1 | tr '\n' ' ')
timeout 5s ./push_swap $ARG | tee /tmp/ps_output.txt | wc -l
timeout 5s ./push_swap $ARG | ./checker_linux $ARG

echo ""
echo "Random sorting tests for 100 elements:"
for i in {1..5}; do
  ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  timeout 5s ./push_swap $ARG | tee /tmp/ps_output.txt | wc -l
  timeout 5s ./push_swap $ARG | ./checker_linux $ARG
done

echo ""
echo "************************************* TESTING 500 ELEMENTS *************************************"

echo "Worst case sorting of 500 elements:"
ARG=$(seq 500 -1 1 | tr '\n' ' ')
timeout 10s ./push_swap $ARG | tee /tmp/ps_output.txt | wc -l
timeout 10s ./push_swap $ARG | ./checker_linux $ARG

echo "Random sorting tests for 500 elements:"
for i in {1..5}; do
  ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
  timeout 10s ./push_swap $ARG | tee /tmp/ps_output.txt | wc -l
  timeout 10s ./push_swap $ARG | ./checker_linux $ARG
done
