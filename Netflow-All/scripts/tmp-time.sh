execs=`ls netflow_* | sed '/\./d'`

if [ $# = 1 ]; then
  file=$1
else 
  file=g200.txt
fi

for i in $execs ; do
  set `csh -c "time $i < $file"`
  f=$4
  t=$5
  p=$7
  echo $i $t $f $p
done
