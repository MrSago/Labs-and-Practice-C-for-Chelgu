all: build start

MATRIX=.\Matrix\Determinant.c .\Matrix\FreeMatrix.c .\Matrix\MatrixFromFile.c .\Matrix\PrintMatrix.c .\Matrix\RandomMatrix.c .\Matrix\ScanMatrix.c
MENU=.\Menu\FileMatrix.c .\Menu\GenRndMatrix.c .\Menu\ManuallyMatrix.c

build:
	gcc -O3 -ansi -o prog.exe .\main.c .\my_exception.c .\ReadLine.c ${MATRIX} ${MENU}

start:
	.\prog.exe