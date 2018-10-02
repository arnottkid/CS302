for imp in s h l ; do
  i=1000
  while [ $i -lt 100000 ]; do
    v=`csh -c "time sh -c './genrandom $i | ./pq_sort $imp > /dev/null'" |
       sed 's/:/ /' | awk '{ printf "%.2f\n", $3*60 + $4 }'`
    echo $imp $i $v
    i=`echo $i | awk '{ print $1+1000 }'`
  done
done
