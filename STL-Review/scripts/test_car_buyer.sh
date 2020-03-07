#!/bin/sh

if [ $# -ne 1 ]; then
  echo 'usage: sh scripts/test_car_buyer.sh executable-name' >&2
  exit 1
fi

i=0
while [ $i -lt 50 ]; do
  "$1" $i
  i=$(($i+1))
done

