set title "Tiempo vs Tamaño del Vector"
set xlabel "n"
set ylabel "Tiempo (ms)"

set logscale x
set logscale y
set grid

plot "tiempos.dat" using 1:2 with linespoints lw 2 pt 7 title "Suma", \
     "tiempos.dat" using 1:3 with linespoints lw 2 pt 7 title "Normalizacion"