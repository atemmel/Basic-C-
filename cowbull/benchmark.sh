#!/usr/bin/bash
max=10000
for run in {1..10000}
do
	./program2 >> stats4
	echo "scale=5 ; $run / $max" | bc
done
