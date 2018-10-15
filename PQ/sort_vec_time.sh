qif [ $# -ne 1 ]; then
  echo 'usage: sort_vec_time n'
  exit 1
fi

genrandom $1 > tmp.txt
( time sort_vec_heap_simp < tmp.txt > /dev/null ) 2>&1 | grep real | awk '{ print $2 }' | sed 's/m/ /' | awk '{ print $1*60.0+$2 }'
( time sort_vec_heap < tmp.txt > /dev/null ) 2>&1 | grep real | awk '{ print $2 }' | sed 's/m/ /' | awk '{ print $1*60.0+$2 }'

