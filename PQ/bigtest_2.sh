for imp in h l ; do
  i=10000
  while [ $i -lt 1000000 ]; do
      for j in 1 2 3 4 5 6 7 8 9 10 ; do
      v=`csh -c "time ./massive_create $imp $i 100" |
       sed 's/:/ /' | awk '{ printf "%.2f\n", $3*60 + $4 }'`
      echo $imp $i $v
      done
    i=`echo $i | awk '{ print $1+10000 }'`
  done
done
