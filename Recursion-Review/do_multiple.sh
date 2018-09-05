if [ $# -ne 2 ]; then
  echo 'usage: sh do_multiple.sh program ngen' >& 2
  exit 1
fi

i=0
while [ $i -lt $2 ]; do
  a=`$1 | wc | awk '{ print $1 }'`
  if [ $a -gt 0 ]; then
    i=`echo $i | awk '{ print $1+1 }'`
    echo $i
  fi
done
