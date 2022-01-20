all: build start

MATRIX=.\Matrix\FreeMatrix.c .\Matrix\MatrixFromFile.c .\Matrix\MultiMatrix.c .\Matrix\TransMatrix.c

build:
	gcc -O3 -ansi -o prog.exe .\main.c .\my_exception.c ${MATRIX}

start:
	.\prog.exe