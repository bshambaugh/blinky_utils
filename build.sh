#!/bin/bash

pio test

# I am not sure how to trigger valgrind in vscode
for f in .pio/build/native/; do
  echo "$f"
#  valgrind -v --log-file="${f%.*}"_memory.txt $f
done
valgrind -v --log-file="valgrind_results.txt" .pio/build/native/program
#for f in *.out; do
#    valgrind -v --log-file="${f%.*}"_memory.txt ./$f
#done
mkdir blinky_utils-master
cd src
for f in *h; do 
     cp "$f" "../blinky_utils/${f%.c}"
     echo "$f"
done
#cp *.h ../blinky_utils/
cd ..
#rm blinky_utils/main.cpp
cp src/library_properties/* blinky_utils-master/
zip -r blinky_utils-master.zip blinky_utils-master/
