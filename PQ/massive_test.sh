if [ $# -ne 1 ]; then
  echo 'usage: sh massive_test.sh nelements'
  exit 1
fi

iterations=`echo $1 | awk '{ if ($1 > 5000000) print 1; else printf("%.0lf\n", 5000000/$1) }'`

( time massive_create_heap_simp $1 $iterations) 2>&1 | grep real | awk '{ print $2 }' | sed 's/m/ /' |
       awk '{ printf "%.6lf\n", ($1*60.0+$2)/'$iterations' }'
( time massive_create_heap $1 $iterations ) 2>&1 | grep real | awk '{ print $2 }' | sed 's/m/ /' |
       awk '{ printf "%.6lf\n",  ($1*60.0+$2)/'$iterations' }'

