{ n++
  t += $4
  e=$2
  it= $3 }
END { printf "%d %.8f\n", e, t/it/n }
