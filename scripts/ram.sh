#!/bin/bash  
FREE_DATA=`free -m | grep Mem` 
FREE=`echo $FREE_DATA | cut -f4 -d' '`
TOTAL=`echo $FREE_DATA | cut -f2 -d' '`
BUFFCACHE=`echo $FREE_DATA | cut -f6 -d' '`
SHARED=`echo $FREE_DATA | cut -f5 -d' '`
USED=$(($TOTAL-$FREE-$BUFFCACHE+$SHARED))
USEDGB=$(printf %.2f "$((10**9 * $USED / 1000))e-9")
TOTALGB=$(printf %.2f "$((10**9 * $TOTAL / 1000))e-9")
echo RAM: $(echo $USEDGB/$TOTALGB) GB
