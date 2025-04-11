#!/bin/bash

for n in 10 50 100 200 300 400 500; do
  total=0
  for i in {1..5}; do
    ARG=$(seq 1 $n | shuf)
    count=$(./push_swap $ARG | wc -l)
    total=$((total + count))
  done
  avg=$((total / 5))
  echo "$n elements → avg $avg ops"
done
