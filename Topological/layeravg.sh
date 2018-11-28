if [ $# -ne 2 ]; then
  echo 'usage sh layeravg.sh topo|dijkstra w' >&2
  exit 1
fi

for i in `sed "s/ .*//" layers.txt | sort -nu` ; do
  echo $i `grep "^$i $2 $1" layers.txt | awk '{ n++; t+= $NF; print t/n }' | tail -n 1 `
done
