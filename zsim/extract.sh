#!/bin/sh -f

bench=$1

`grep -w "cycles"  outputs/hw4/LRU/${bench}/zsim.out | awk -F " " '{print "cylces " $2}' | head -1`
`grep -w "cCycles" outputs/hw4/LRU/${bench}/zsim.out | awk -F " " '{print "cCycles " $2 }' | head -1`




