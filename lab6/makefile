all: build start

NUMFUNC=.\NumFunctions\Addition.c .\NumFunctions\CopyNumbers.c .\NumFunctions\Multiplication.c .\NumFunctions\NumberFromFile.c .\NumFunctions\PrintNumber.c

build:
	gcc -O3 -ansi -o prog.exe .\main.c .\FileCheck.c ${NUMFUNC}

start:
	.\prog.exe