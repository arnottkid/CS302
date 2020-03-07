#!/bin/sh

if [ $# -ne 1 ]; then
  echo 'usage: sh scripts/test_colorful_bricks.sh executable-name' >&2
  exit 1
fi

if [ ! -f "$1" ]; then
  echo "no file $1" >&2
  exit 1
fi

i=0
while [ $i -lt 300 ]; do
  "$1" $i
  i=$(($i+1))
done

