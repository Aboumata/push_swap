#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

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
echo "************************************* TESTING EDGE CASES ***************************************"

# Already Sorted
echo -e "${GREEN}Testing already sorted list:${NC}"
timeout 5s ./push_swap 1 2 3 4 5 | tee /tmp/ps_output.txt | wc -l
timeout 5s ./push_swap 1 2 3 4 5 | ./checker_linux 1 2 3 4 5

# Reverse Sorted
echo -e "${GREEN}Testing reverse sorted list:${NC}"
timeout 5s ./push_swap 5 4 3 2 1 | tee /tmp/ps_output.txt | wc -l
timeout 5s ./push_swap 5 4 3 2 1 | ./checker_linux 5 4 3 2 1

# Duplicates (should print error)
echo -e "${RED}Testing with duplicates (should print error):${NC}"
timeout 5s ./push_swap 1 2 3 3 4 5

# Invalid input (should print error)
echo -e "${RED}Testing with invalid input (letters, should print error):${NC}"
timeout 5s ./push_swap 1 2 a 3 4

# Large Numbers (should print error)
echo -e "${RED}Testing with numbers out of int range (should print error):${NC}"
timeout 5s ./push_swap 1 2 2147483648 3 4

echo ""
echo "************************************* TESTING 100 ELEMENTS *************************************"

echo "Random sorting tests for 100 elements:"
for i in {1..5}; do
  ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  OPS=$(timeout 5s ./push_swap $ARG | tee /tmp/ps_output.txt | wc -l)
  RESULT=$(timeout 5s ./push_swap $ARG | ./checker_linux $ARG)

  echo -n "Operations: $OPS | "
  if [ "$RESULT" == "OK" ]; then
    if [ "$OPS" -le 700 ]; then
      echo -e "${GREEN}OK (within 700 moves)${NC}"
    else
      echo -e "${RED}Too many moves! (>700)${NC}"
    fi
  else
    echo -e "${RED}KO (sorting failed)${NC}"
  fi
done

echo ""
echo "************************************* TESTING 500 ELEMENTS *************************************"

echo "Random sorting tests for 500 elements:"
for i in {1..5}; do
  ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
  OPS=$(timeout 10s ./push_swap $ARG | tee /tmp/ps_output.txt | wc -l)
  RESULT=$(timeout 10s ./push_swap $ARG | ./checker_linux $ARG)

  echo -n "Operations: $OPS | "
  if [ "$RESULT" == "OK" ]; then
    if [ "$OPS" -le 5500 ]; then
      echo -e "${GREEN}OK (within 5500 moves)${NC}"
    else
      echo -e "${RED}Too many moves! (>5500)${NC}"
    fi
  else
    echo -e "${RED}KO (sorting failed)${NC}"
  fi
done

if [[ $# -eq 1 ]]; then
  echo ""
  echo "************************************* TESTING SINGLE ARGUMENT INPUT *************************************"

  ARG=$1
  OPS=$(timeout 5s ./push_swap $ARG | tee /tmp/ps_output.txt | wc -l)
  RESULT=$(timeout 5s ./push_swap $ARG | ./checker_linux $ARG)

  echo -n "Operations: $OPS | "
  if [ "$RESULT" == "OK" ]; then
    echo -e "${GREEN}OK${NC}"
  else
    echo -e "${RED}KO (sorting failed)${NC}"
  fi
fi
